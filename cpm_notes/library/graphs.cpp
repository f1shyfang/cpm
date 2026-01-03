/**
 * graphs.cpp
 * Standard Graph Algorithms.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e18;

// 1. Dijkstra (Shortest Path)
void dijkstra(int s, int n, vector<vector<pii>> &adj, vector<ll> &dist) {
  dist.assign(n + 1, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue;
    for (auto &[v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
}

// 2. Lowest Common Ancestor (LCA)
const int MAXN = 100005;
const int LOG = 20;
vector<int> adj[MAXN];
int up[MAXN][LOG], depth[MAXN];

void dfs(int u, int p) {
  depth[u] = depth[p] + 1;
  up[u][0] = p;
  for (int i = 1; i < LOG; i++)
    up[u][i] = up[up[u][i - 1]][i - 1];
  for (int v : adj[u])
    if (v != p)
      dfs(v, u);
}

int lca(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);
  for (int i = LOG - 1; i >= 0; i--)
    if (depth[u] - (1 << i) >= depth[v])
      u = up[u][i];
  if (u == v)
    return u;
  for (int i = LOG - 1; i >= 0; i--)
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  return up[u][0];
}

int main() {
  int n = 5;
  // Example usage would go here
  return 0;
}
