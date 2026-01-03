/**
 * 04_vectors_arrays.cpp
 *
 * Vectors are dynamic arrays that can grow in size. They are the most used data
 * structure in CP.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
  // 1. Creating and Adding
  vector<int> v;
  v.push_back(5); // [5]
  v.push_back(2); // [5, 2]
  v.push_back(8); // [5, 2, 8]

  // 2. Accessing
  cout << "Second element: " << v[1] << "\n"; // 2 (0-indexed)
  cout << "Size: " << v.size() << "\n";       // 3

  // 3. Sorting (Very Important)
  // sort takes start and end iterators
  sort(v.begin(), v.end()); // [2, 5, 8]

  cout << "Sorted: ";
  for (int x : v)
    cout << x << " ";
  cout << "\n";

  // 4. Resizing
  vector<int> vec(5, -1); // Creates vector of size 5 filled with -1
                          // [-1, -1, -1, -1, -1]
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
