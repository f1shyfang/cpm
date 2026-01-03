// Example 4: STL Algorithms (sort, search, etc.)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // ===== SORT =====
    cout << "=== Sorting ===\n";
    cout << "Original: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
    
    sort(v.begin(), v.end());  // Ascending order
    cout << "Sorted (asc): ";
    for (int x : v) cout << x << " ";
    cout << "\n";
    
    sort(v.begin(), v.end(), greater<int>());  // Descending order
    cout << "Sorted (desc): ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";
    
    // Sort back to ascending for other examples
    sort(v.begin(), v.end());
    
    // ===== MIN / MAX =====
    cout << "=== Min / Max ===\n";
    cout << "min(3, 7) = " << min(3, 7) << "\n";
    cout << "max(3, 7) = " << max(3, 7) << "\n";
    cout << "min element in v: " << *min_element(v.begin(), v.end()) << "\n";
    cout << "max element in v: " << *max_element(v.begin(), v.end()) << "\n\n";
    
    // ===== BINARY SEARCH (requires sorted array) =====
    cout << "=== Binary Search ===\n";
    cout << "v = ";
    for (int x : v) cout << x << " ";
    cout << "\n";
    
    // Check if element exists
    cout << "5 exists? " << (binary_search(v.begin(), v.end(), 5) ? "Yes" : "No") << "\n";
    cout << "10 exists? " << (binary_search(v.begin(), v.end(), 10) ? "Yes" : "No") << "\n";
    
    // lower_bound: first element >= x
    auto lb = lower_bound(v.begin(), v.end(), 5);
    cout << "lower_bound(5) = " << *lb << " at index " << (lb - v.begin()) << "\n";
    
    // upper_bound: first element > x
    auto ub = upper_bound(v.begin(), v.end(), 5);
    cout << "upper_bound(5) = " << *ub << " at index " << (ub - v.begin()) << "\n\n";
    
    // ===== REVERSE =====
    cout << "=== Reverse ===\n";
    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";
    
    // ===== UNIQUE (remove consecutive duplicates) =====
    cout << "=== Unique ===\n";
    vector<int> dup = {1, 1, 2, 2, 2, 3, 3, 4};
    cout << "Before unique: ";
    for (int x : dup) cout << x << " ";
    cout << "\n";
    
    // unique moves duplicates to end, returns iterator to new end
    auto newEnd = unique(dup.begin(), dup.end());
    dup.erase(newEnd, dup.end());  // Actually remove them
    
    cout << "After unique: ";
    for (int x : dup) cout << x << " ";
    cout << "\n\n";
    
    // ===== COUNT / FIND =====
    cout << "=== Count / Find ===\n";
    vector<int> nums = {1, 2, 3, 2, 4, 2, 5};
    cout << "Count of 2: " << count(nums.begin(), nums.end(), 2) << "\n";
    
    auto it = find(nums.begin(), nums.end(), 3);
    if (it != nums.end()) {
        cout << "Found 3 at index " << (it - nums.begin()) << "\n";
    }
    cout << "\n";
    
    // ===== ACCUMULATE (sum) =====
    cout << "=== Accumulate ===\n";
    vector<int> arr = {1, 2, 3, 4, 5};
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    cout << "Sum of {1,2,3,4,5} = " << sum << "\n\n";
    
    // ===== NEXT_PERMUTATION =====
    cout << "=== Permutations ===\n";
    vector<int> perm = {1, 2, 3};
    cout << "All permutations of {1,2,3}:\n";
    do {
        for (int x : perm) cout << x << " ";
        cout << "\n";
    } while (next_permutation(perm.begin(), perm.end()));
    
    return 0;
}

/*
To compile and run:
    g++ 04_stl_algorithms.cpp -o 04_stl_algorithms
    ./04_stl_algorithms
*/
