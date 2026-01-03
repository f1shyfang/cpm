/**
 * data_structures.cpp
 * Standard competitive programming data structures.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1. Disjoint Set Union (DSU)
struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    size.assign(n, 1);
  }
  int find(int i) { return parent[i] == i ? i : parent[i] = find(parent[i]); }
  void unite(int i, int j) {
    int root_i = find(i), root_j = find(j);
    if (root_i != root_j) {
      if (size[root_i] < size[root_j])
        swap(root_i, root_j);
      parent[root_j] = root_i;
      size[root_i] += size[root_j];
    }
  }
};

// 2. Fenwick Tree (Binary Indexed Tree)
struct Fenwick {
  int n;
  vector<ll> tree;
  Fenwick(int n) : n(n), tree(n + 1, 0) {}
  void add(int i, int delta) {
    for (++i; i <= n; i += i & -i)
      tree[i] += delta;
  }
  ll query(int i) {
    ll sum = 0;
    for (++i; i > 0; i -= i & -i)
      sum += tree[i];
    return sum;
  }
  ll query(int l, int r) { return query(r) - query(l - 1); }
};

// 3. Segment Tree
struct SegTree {
  int n;
  vector<ll> tree;
  SegTree(int n) : n(n), tree(4 * n, 0) {}
  void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
      tree[node] = val;
      return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
      update(2 * node, start, mid, idx, val);
    else
      update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
      return 0;
    if (l <= start && end <= r)
      return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) +
           query(2 * node + 1, mid + 1, end, l, r);
  }
};

int main() {
  DSU d(10);
  d.unite(1, 2);
  cout << "1 and 2 connected: " << (d.find(1) == d.find(2)) << "\n";
  return 0;
}
