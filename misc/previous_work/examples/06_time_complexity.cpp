// Chapter 2: Time Complexity Examples
// Understanding Big O notation and algorithm efficiency
#include <bits/stdc++.h>
using namespace std;

// ===== O(1) - Constant Time =====
// Accessing array element, arithmetic operations
int constantTime(vector<int>& arr) {
    return arr[0] + arr[1];  // Always same number of operations
}

// ===== O(log n) - Logarithmic Time =====
// Binary search - halves the search space each iteration
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// ===== O(n) - Linear Time =====
// Single loop through array
int linearSum(vector<int>& arr) {
    int sum = 0;
    for (int x : arr) sum += x;
    return sum;
}

// ===== O(n log n) - Linearithmic Time =====
// Sorting algorithms (merge sort, heap sort)
void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());  // O(n log n)
}

// ===== O(n^2) - Quadratic Time =====
// Nested loops - check all pairs
int countPairsWithSum(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) count++;
        }
    }
    return count;
}

// ===== O(n^3) - Cubic Time =====
// Three nested loops - check all triplets
int countTripletsWithSum(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == target) count++;
            }
        }
    }
    return count;
}

// ===== O(2^n) - Exponential Time =====
// Generate all subsets
void generateSubsets(vector<int>& arr) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cout << arr[i] << " ";
        }
        cout << "}\n";
    }
}

// ===== O(n!) - Factorial Time =====
// Generate all permutations
void generatePermutations(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    do {
        for (int x : arr) cout << x << " ";
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    Time Complexity Cheat Sheet (for n = 10^6):
    
    O(1)        -> instant
    O(log n)    -> ~20 operations
    O(n)        -> 10^6 operations (~0.01s)
    O(n log n)  -> ~2 * 10^7 operations (~0.2s)
    O(n^2)      -> 10^12 operations (TOO SLOW!)
    O(2^n)      -> only works for n <= 20-25
    O(n!)       -> only works for n <= 10-11
    
    Rule of thumb: 10^8 operations per second
    */
    
    vector<int> arr = {1, 2, 3, 4, 5};
    
    cout << "=== O(1) Constant ===\n";
    cout << "First two elements sum: " << constantTime(arr) << "\n\n";
    
    cout << "=== O(log n) Binary Search ===\n";
    cout << "Index of 3: " << binarySearch(arr, 3) << "\n\n";
    
    cout << "=== O(n) Linear Sum ===\n";
    cout << "Sum: " << linearSum(arr) << "\n\n";
    
    cout << "=== O(n^2) Count Pairs ===\n";
    cout << "Pairs summing to 5: " << countPairsWithSum(arr, 5) << "\n\n";
    
    cout << "=== O(2^n) All Subsets ===\n";
    vector<int> small = {1, 2, 3};
    generateSubsets(small);
    cout << "\n";
    
    cout << "=== O(n!) All Permutations ===\n";
    generatePermutations(small);
    
    return 0;
}
