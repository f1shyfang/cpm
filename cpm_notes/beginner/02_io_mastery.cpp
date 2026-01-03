/**
 * 02_io_mastery.cpp
 *
 * Learn how to read input and print output efficiently.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
  // 1. Reading basic types
  int a;
  long long b;
  string s;

  // Simulate input for demonstration (usually you just use cin >> ...)
  // Input: 10 10000000000 Hello
  // cin >> a >> b >> s;

  // cout << "Read: " << a << " " << b << " " << s << "\n";

  // 2. Reading a whole line
  // CAUTION: mixing cin >> and getline() can be tricky.
  // cin leaves a newline character in the buffer, which getline reads as an
  // empty line. string line; getline(cin, line);

  // 3. Output formatting
  double pi = 3.1415926535;
  cout << fixed << setprecision(4) << pi << "\n"; // Prints 3.1416
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
