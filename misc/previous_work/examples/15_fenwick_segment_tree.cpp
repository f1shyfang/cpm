// Fenwick Tree (BIT) and Segment Tree for range sum / point update
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Fenwick {
    int n; vector<ll> bit;
    Fenwick(int sz = 0) { init(sz); }
    void init(int sz) { n = sz; bit.assign(n + 1, 0); }
    void add(int idx, ll delta) { // idx: 0-based external, 1-based internal
        for (idx++; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    ll sumPrefix(int idx) const { // sum [0, idx]
        ll res = 0;
        for (idx++; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    ll sumRange(int l, int r) const { return sumPrefix(r) - (l ? sumPrefix(l-1) : 0); }
};

struct SegTree {
    int n; vector<ll> st;
    SegTree(int n = 0) { init(n); }
    void init(int n_) {
        n = 1; while (n < n_) n <<= 1;
        st.assign(2 * n, 0);
    }
    void build(const vector<ll>& a) {
        init((int)a.size());
        for (int i = 0; i < (int)a.size(); i++) st[n + i] = a[i];
        for (int i = n - 1; i >= 1; i--) st[i] = st[2*i] + st[2*i+1];
    }
    void pointUpdate(int idx, ll val) {
        int p = n + idx; st[p] = val;
        for (p >>= 1; p >= 1; p >>= 1) st[p] = st[2*p] + st[2*p+1];
    }
    ll rangeQuery(int l, int r) const { // inclusive
        l += n; r += n; ll res = 0;
        while (l <= r) {
            if (l & 1) res += st[l++];
            if (!(r & 1)) res += st[r--];
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> a = {3, 1, 4, 1, 5, 9, 2};
    cout << "Array: "; for (auto x : a) cout << x << " "; cout << "\n\n";

    cout << "=== Fenwick (prefix sums) ===\n";
    Fenwick fw(a.size());
    for (int i = 0; i < (int)a.size(); i++) fw.add(i, a[i]);
    cout << "sum [0,3] = " << fw.sumRange(0,3) << "\n";
    cout << "sum [2,5] = " << fw.sumRange(2,5) << "\n";
    fw.add(3, +10); // point add
    cout << "after add 10 at index 3, sum [2,5] = " << fw.sumRange(2,5) << "\n\n";

    cout << "=== Segment Tree (range sum, point set) ===\n";
    SegTree st; st.build(a);
    cout << "sum [0,3] = " << st.rangeQuery(0,3) << "\n";
    cout << "sum [2,5] = " << st.rangeQuery(2,5) << "\n";
    st.pointUpdate(3, 100);
    cout << "after set index 3 = 100, sum [2,5] = " << st.rangeQuery(2,5) << "\n";
    return 0;
}
