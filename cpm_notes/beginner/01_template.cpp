/**
 * 01_template.cpp
 *
 * This is the basic structure of every C++ program you will write for
 * Competitive Programming.
 *
 * Key Parts:
 * 1. #include <bits/stdc++.h> : Finds all standard libraries.
 * 2. using namespace std;    : Lets you use 'cout' instead of 'std::cout'.
 * 3. fast I/O                : Makes your program read/write faster.
 */

#include <bits/stdc++.h>
using namespace std;

// The solve function contains the logic for a single test case
void solve() {
  // Write your code here
  cout << "Hello, Competitive Programming!" << "\n";
}

int main() {
  // Fast I/O lines - Always include these!
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t; // Uncomment this line if the problem has multiple test cases
  while (t--) {
    solve();
  }

  return 0;
}
