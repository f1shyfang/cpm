/**
 * 05_strings.cpp
 *
 * Strings are sequences of characters. In C++, they are mutable (changeable).
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s = "Result";

  // 1. Modifying
  s += " is";   // "Result is"
  s += " Good"; // "Result is Good"

  // 2. Length
  cout << "Length: " << s.length() << "\n";

  // 3. Substring
  // s.substr(index, length)
  cout << "First word: " << s.substr(0, 6) << "\n"; // "Result"

  // 4. Finding patterns
  // returns index or string::npos if not found
  if (s.find("Good") != string::npos) {
    cout << "Found 'Good' in the string!\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
