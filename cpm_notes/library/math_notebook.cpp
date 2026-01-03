/**
 * math_notebook.cpp
 * Implementations of common math algorithms.
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 1. Modular Arithmetic
const int MOD = 1e9 + 7;
struct ModInt {
  int val;
  ModInt(ll v = 0) : val(v % MOD) {
    if (val < 0)
      val += MOD;
  }
  ModInt operator+(ModInt o) const { return val + o.val; }
  ModInt operator-(ModInt o) const { return val - o.val; }
  ModInt operator*(ModInt o) const { return (ll)val * o.val; }
  ModInt pow(ll e) const {
    ModInt res = 1, b = *this;
    while (e) {
      if (e & 1)
        res = res * b;
      b = b * b;
      e >>= 1;
    }
    return res;
  }
  ModInt inv() const { return pow(MOD - 2); }
};

// 2. Sieve of Eratosthenes
const int N = 1e6 + 5;
int spf[N]; // Smallest Prime Factor
void sieve() {
  iota(spf, spf + N, 0);
  for (int i = 2; i * i < N; ++i) {
    if (spf[i] == i) {
      for (int j = i * i; j < N; j += i)
        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

// 3. nCr
ModInt fact[N], invFact[N];
void init_nCr() {
  fact[0] = 1;
  for (int i = 1; i < N; i++)
    fact[i] = fact[i - 1] * i;
  invFact[N - 1] = fact[N - 1].inv();
  for (int i = N - 2; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1);
}

ModInt nCr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  return fact[n] * invFact[r] * invFact[n - r];
}

int main() {
  // Demonstration
  init_nCr();
  cout << "5 choose 2: " << nCr(5, 2).val << "\n";
  return 0;
}
