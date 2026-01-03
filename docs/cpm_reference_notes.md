# The Ultimate C++ Competitive Programming Reference

**Target Audience**: Intermediate to Advanced Competitive Programmers (Codeforces Cyan+)
**Language Standard**: C++17 / C++20

---

## 1. Template & Environment

### Standard Contest Template
 Optimized for speed and typing efficiency.

```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

// Types
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// Utils
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define f first
#define s second
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)

// Debugging (Delete in submission)
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

void solve() {
    // Check for overflow!
    // Check edge cases (n=1, n=0)!
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
```

### Policy Based Data Structures (Indexed Set)
Useful for "k-th element" and "count loop < x" queries in O(log n).

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Usage:
// oset<int> s;
// s.insert(x);
// s.find_by_order(k); // returns iterator to k-th smallest element (0-indexed)
// s.order_of_key(x);  // returns number of elements strictly smaller than x
```

---

## 2. Mathematics

### Modular Arithmetic Class
Safe modular arithmetic operations.

```cpp
template <int MOD_> struct ModInt {
    static constexpr int MOD = MOD_;
    static_assert(MOD <= (int)2e9, "MOD must be less than 2e9");
    long long val;
    ModInt(long long v = 0) : val(v % MOD) { if (val < 0) val += MOD; }
    ModInt operator+(const ModInt& other) const { return ModInt(val + other.val); }
    ModInt operator-(const ModInt& other) const { return ModInt(val - other.val); }
    ModInt operator*(const ModInt& other) const { return ModInt(val * other.val); }
    ModInt pow(long long e) const {
        ModInt res = 1, base = *this;
        while (e) { if (e & 1) res = res * base; base = base * base; e >>= 1; }
        return res;
    }
    ModInt inv() const { return pow(MOD - 2); }
    ModInt operator/(const ModInt& other) const { return *this * other.inv(); }
};
using Mint = ModInt<1000000007>;
```

### Sieve of Eratosthenes (Linear Sieve)
Computes primes and smallest prime factor (spf) in O(N).

```cpp
const int N = 1e6 + 5;
int spf[N]; // Smallest Prime Factor
vector<int> primes;

void sieve() {
    iota(spf, spf + N, 0);
    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) primes.pb(i);
        for (int p : primes) {
            if (p > spf[i] || (ll)i * p >= N) break;
            spf[i * p] = p;
        }
    }
}
```

### Combinatorics (nCr)
Precompute factorials for O(1) queries.

```cpp
Mint fact[N], invFact[N];
void init_nCr() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
    invFact[N - 1] = fact[N - 1].inv();
    for (int i = N - 2; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1);
}

Mint nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] * invFact[n - r];
}
```

---

## 3. Data Structures

### Disjoint Set Union (DSU)
With path compression and union by size.

```cpp
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n); iota(all(parent), 0);
        size.assign(n, 1);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }
};
```

### Fenwick Tree (Binary Indexed Tree)
Point update, Prefix sum in O(log N). Very low constant factor.

```cpp
struct Fenwick {
    int n; vector<ll> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }
    ll query(int i) {
        ll sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    ll query(int l, int r) { // sum [l, r]
        return query(r) - query(l - 1);
    }
};
```

### Segment Tree (Recursive with Lazy Propagation)
Range update, Range query in O(log N).

```cpp
struct SegTree {
    int n;
    vll tree, lazy;
    SegTree(int n) : n(n), tree(4 * n), lazy(4 * n, 0) {}

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node]; // Logic depends on op
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    // Call: update(1, 0, n-1, l, r, val);
};
```

---

## 4. Graph Algorithms

### Dijkstra (Shortest Path)
O(E log V).

```cpp
void dijkstra(int s, vector<vector<pii>>& adj, vector<ll>& dist) {
    dist.assign(adj.size(), INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
```

### Lowest Common Ancestor (Binary Lifting)
O(N log N) preprocess, O(log N) query.

```cpp
const int LOG = 20;
int up[N][LOG], depth[N];
vector<int> adj[N];

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int i = 1; i < LOG; i++)
        up[u][i] = up[up[u][i-1]][i-1];
    for (int v : adj[u])
        if (v != p) dfs(v, u);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (up[u][i] != up[v][i]) {
            u = up[u][i]; v = up[v][i];
        }
    return up[u][0];
}
```

---

## 5. String Algorithms

### KMP Algorithm (Knuth-Morris-Pratt)
Finds all occurrences of pattern P in text T in O(N+M).

```cpp
vector<int> pi_function(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
```

### Rolling Hash
Compare strings in O(1).

```cpp
struct StringHash {
    vector<ll> h, p;
    ll MOD = 1e9+7, B = 31;
    StringHash(string s) {
        int n = s.size();
        h.resize(n+1, 0); p.resize(n+1, 1);
        for(int i=0; i<n; i++) {
            h[i+1] = (h[i] * B + s[i]) % MOD;
            p[i+1] = (p[i] * B) % MOD;
        }
    }
    ll get(int l, int r) { // 0-indexed [l, r]
        return (h[r+1] - h[l] * p[r-l+1] % MOD + MOD) % MOD;
    }
};
```

---

## 6. Miscellaneous & Tricks

### Coordinate Compression
Map large values to [0, N-1] relative order.

```cpp
void compress(vector<int>& a) {
    vector<int> vals = a;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for(int& x : a) x = lower_bound(all(vals), x) - vals.begin();
}
```

### Custom Hash for unordered_map
Prevents hash collision attacks on Codeforces.

```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// unordered_map<long long, int, custom_hash> safe_map;
```

### Bit Manipulation

- **Check if power of 2**: `!(x & (x - 1))`
- **Number of set bits**: `__builtin_popcount(x)` / `__builtin_popcountll(x)`
- **Leading zeros**: `__builtin_clz(x)`
- **Trailing zeros**: `__builtin_ctz(x)`
- **LSB**: `x & -x`

---

*This document serves as a quick reference. For deep dives, consult CP-Algorithms or the C++ STL Documentation.*
