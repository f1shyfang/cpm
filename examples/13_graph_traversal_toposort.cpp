// BFS, DFS, connected components, and topological sort (Kahn)
#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& g) {
    vector<int> dist(g.size(), -1);
    queue<int> q; q.push(start); dist[start] = 0;
    cout << "BFS order: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    cout << "\nDistances: ";
    for (int d : dist) cout << d << " ";
    cout << "\n\n";
}

void dfs(int u, const vector<vector<int>>& g, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : g[u]) if (!vis[v]) dfs(v, g, vis);
}

int countComponents(const vector<vector<int>>& g) {
    vector<int> vis(g.size());
    int comp = 0;
    for (int i = 0; i < (int)g.size(); i++) if (!vis[i]) {
        comp++;
        dfs(i, g, vis);
        cout << "| ";
    }
    cout << "\n";
    return comp;
}

// Topological sort (Kahn). Returns empty if cycle.
vector<int> topoKahn(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) for (int v : g[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != n) return {}; // cycle detected
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Undirected example for BFS/DFS/components
    vector<vector<int>> g = {
        {1,2},    // 0
        {0,3},    // 1
        {0},      // 2
        {1,4},    // 3
        {3},      // 4
    };

    cout << "=== BFS from 0 ===\n";
    bfs(0, g);

    cout << "=== DFS components ===\n";
    int comps = countComponents(g);
    cout << "Components: " << comps << "\n\n";

    // DAG for topo sort
    vector<vector<int>> dag = {
        {1,2}, // 0 -> 1,2
        {3},   // 1 -> 3
        {3},   // 2 -> 3
        {4},   // 3 -> 4
        {}     // 4
    };

    cout << "=== Topological Sort (Kahn) ===\n";
    vector<int> order = topoKahn(dag);
    if (order.empty()) cout << "Cycle detected, no topo order\n";
    else {
        for (int x : order) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
