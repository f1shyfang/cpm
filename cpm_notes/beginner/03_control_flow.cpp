/**
 * 03_control_flow.cpp
 *
 * Examples of making decisions (if/else) and repeating actions (loops).
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x = 10;

  // 1. If / Else
  if (x > 5) {
    cout << "x is greater than 5\n";
  } else {
    cout << "x is small\n";
  }

  // 2. For Loop (Fixed repetitions)
  // Print 0 1 2 3 4
  cout << "For Loop: ";
  for (int i = 0; i < 5; i++) {
    cout << i << " ";
  }
  cout << "\n";

  // 3. While Loop (Repeat until condition is false)
  cout << "While Loop: ";
  int n = 5;
  while (n > 0) {
    cout << n << " ";
    n--;
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
