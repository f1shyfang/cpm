/**
 * strings.cpp
 * String Processing Algorithms.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1. KMP Algorithm (Prefix Function)
vector<int> pi_function(string s) {
  int n = s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

// 2. Rolling Hash
struct StringHash {
  vector<ll> h, p;
  ll MOD = 1e9 + 7, B = 31;
  StringHash(string s) {
    int n = s.size();
    h.resize(n + 1, 0);
    p.resize(n + 1, 1);
    for (int i = 0; i < n; i++) {
      h[i + 1] = (h[i] * B + s[i]) % MOD;
      p[i + 1] = (p[i] * B) % MOD;
    }
  }
  ll get(int l, int r) { // 0-indexed [l, r]
    return (h[r + 1] - h[l] * p[r - l + 1] % MOD + MOD) % MOD;
  }
};

int main() {
  string s = "abacaba";
  vector<int> pi = pi_function(s);
  cout << "Pi[1] (b): " << pi[1] << "\n";
  return 0;
}
