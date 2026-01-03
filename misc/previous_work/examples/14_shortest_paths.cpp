// Shortest paths: BFS (unweighted), Dijkstra (non-negative), Bellman-Ford (neg edges)
#include <bits/stdc++.h>
using namespace std;

// Unweighted shortest path from source
vector<int> bfsDist(int s, const vector<vector<int>>& g) {
    vector<int> dist(g.size(), -1);
    queue<int> q; q.push(s); dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}

// Dijkstra with priority queue: O((n+m) log n)
vector<long long> dijkstra(int s, const vector<vector<pair<int,int>>>& g) {
    const long long INF = 4e18;
    vector<long long> dist(g.size(), INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v,w] : g[u]) if (dist[v] > d + w) {
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
    return dist;
}

// Bellman-Ford: detects negative cycles reachable from s
vector<long long> bellmanFord(int s, int n, const vector<tuple<int,int,int>>& edges) {
    const long long INF = 4e18;
    vector<long long> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (auto [u,v,w] : edges) {
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    // One more pass to check negative cycle
    for (auto [u,v,w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            cerr << "Negative cycle detected involving edge " << u << "->" << v << "\n";
            break;
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== BFS (Unweighted) ===\n";
    vector<vector<int>> g = {{1,2},{0,3},{0,3},{1,2,4},{3}};
    auto d0 = bfsDist(0, g);
    for (int d : d0) cout << d << " ";
    cout << "\n\n";

    cout << "=== Dijkstra (Non-negative) ===\n";
    vector<vector<pair<int,int>>> wg(5);
    auto addEdge = [&](int u, int v, int w){ wg[u].push_back({v,w}); wg[v].push_back({u,w}); };
    addEdge(0,1,4); addEdge(0,2,1); addEdge(2,1,2); addEdge(1,3,1); addEdge(2,3,5); addEdge(3,4,3);
    auto dist = dijkstra(0, wg);
    for (auto d : dist) cout << d << " ";
    cout << "\n\n";

    cout << "=== Bellman-Ford (Negative edges) ===\n";
    vector<tuple<int,int,int>> edges = {
        {0,1,1}, {1,2,-1}, {2,3,-1}, {3,1,-1}, // negative cycle reachable
        {0,4,10}
    };
    auto bf = bellmanFord(0, 5, edges);
    for (auto d : bf) cout << (d >= 4e18/2 ? 999999 : d) << " ";
    cout << "\n";
    return 0;
}
