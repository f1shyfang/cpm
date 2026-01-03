/**
 * 06_simple_algos.cpp
 *
 * Common simple algorithms and built-in functions.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
  // 1. Min and Max
  int a = 10, b = 25;
  cout << "Max: " << max(a, b) << "\n"; // 25
  cout << "Min: " << min(a, b) << "\n"; // 10

  vector<int> v = {1, 5, 2, 9};
  // Finding max element in a vector
  int max_val = *max_element(v.begin(), v.end());
  cout << "Max in vector: " << max_val << "\n";

  // 2. Swap
  swap(a, b);
  // Now a is 25, b is 10

  // 3. GCD (Greatest Common Divisor)
  cout << "GCD(12, 18) = " << __gcd(12, 18) << "\n"; // 6

  // 4. Frequency Array (Counting)
  // Count how many times each number appears
  vector<int> nums = {1, 2, 1, 3, 2, 1};
  int count[10] = {0}; // array of size 10 initialized to 0

  for (int x : nums) {
    count[x]++;
  }

  cout << "Count of 1s: " << count[1] << "\n"; // 3
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
