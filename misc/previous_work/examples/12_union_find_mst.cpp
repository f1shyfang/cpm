// Disjoint Set Union (Union-Find) + Kruskal MST + cycle detection
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

struct Edge { int u, v, w; };

// Kruskal: O(m log m)
pair<int, vector<Edge>> kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return a.w < b.w; });
    DSU dsu(n);
    int cost = 0; vector<Edge> mst;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cost += e.w;
            mst.push_back(e);
        }
    }
    return {cost, mst};
}

// Cycle detection in undirected graph using DSU
bool hasCycle(int n, const vector<Edge>& edges) {
    DSU dsu(n);
    for (auto &e : edges) {
        if (!dsu.unite(e.u, e.v)) return true;  // edge joins same component
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Edge> edges = {
        {0,1,4}, {0,2,3}, {1,2,1}, {1,3,2}, {2,3,4}, {3,4,2}, {4,5,6}
    };
    int n = 6; // nodes 0..5

    cout << "=== Cycle Detection ===\n";
    cout << (hasCycle(n, edges) ? "Graph has cycle" : "Graph acyclic") << "\n\n";

    cout << "=== Kruskal MST ===\n";
    auto [cost, mst] = kruskal(n, edges);
    cout << "MST cost = " << cost << "\nEdges: \n";
    for (auto &e : mst) cout << e.u << "-" << e.v << " (" << e.w << ")\n";
    return 0;
}
