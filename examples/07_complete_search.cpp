// Chapter 5: Complete Search (Brute Force)
// Try all possibilities to find the solution
#include <bits/stdc++.h>
using namespace std;

// ===== GENERATING SUBSETS =====
// Method 1: Using bitmask
void subsetsWithBitmask(vector<int>& arr) {
    int n = arr.size();
    cout << "All " << (1 << n) << " subsets:\n";
    
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }
}

// Method 2: Using recursion
vector<int> current;
void subsetsRecursive(vector<int>& arr, size_t idx) {
    if (idx == arr.size()) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "}\n";
        return;
    }
    // Don't include arr[idx]
    subsetsRecursive(arr, idx + 1);
    // Include arr[idx]
    current.push_back(arr[idx]);
    subsetsRecursive(arr, idx + 1);
    current.pop_back();
}

// ===== GENERATING PERMUTATIONS =====
// Method 1: Using next_permutation
void permutationsSTL(vector<int> arr) {
    sort(arr.begin(), arr.end());
    cout << "All permutations:\n";
    do {
        for (int x : arr) cout << x << " ";
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));
}

// Method 2: Using recursion (backtracking)
void permutationsRecursive(vector<int>& arr, size_t idx) {
    if (idx == arr.size()) {
        for (int x : arr) cout << x << " ";
        cout << "\n";
        return;
    }
    for (size_t i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        permutationsRecursive(arr, idx + 1);
        swap(arr[idx], arr[i]);  // backtrack
    }
}

// ===== BACKTRACKING: N-Queens Problem =====
// Place n queens on n×n board so no two attack each other
int nQueensSolutions;
vector<int> queens;  // queens[row] = column

bool isValidPlacement(int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = queens[r];
        // Same column or same diagonal
        if (c == col || abs(r - row) == abs(c - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row, int n) {
    if (row == n) {
        nQueensSolutions++;
        // Print the solution
        cout << "Solution " << nQueensSolutions << ":\n";
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << (queens[r] == c ? "Q " : ". ");
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isValidPlacement(row, col)) {
            queens.push_back(col);
            solveNQueens(row + 1, n);
            queens.pop_back();  // backtrack
        }
    }
}

// ===== SUBSET SUM: Can we make target sum from subset? =====
bool subsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum == target) return true;
    }
    return false;
}

// ===== MEET IN THE MIDDLE =====
// Split search space in half for O(2^(n/2)) instead of O(2^n)
bool subsetSumMeetInMiddle(vector<int>& arr, int target) {
    int n = arr.size();
    int half = n / 2;
    
    // Generate all subset sums of first half
    set<int> firstHalfSums;
    for (int mask = 0; mask < (1 << half); mask++) {
        int sum = 0;
        for (int i = 0; i < half; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }
        firstHalfSums.insert(sum);
    }
    
    // Check second half: for each sum, check if (target - sum) exists in first half
    for (int mask = 0; mask < (1 << (n - half)); mask++) {
        int sum = 0;
        for (int i = 0; i < n - half; i++) {
            if (mask & (1 << i)) sum += arr[half + i];
        }
        if (firstHalfSums.count(target - sum)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "===== SUBSETS WITH BITMASK =====\n";
    vector<int> arr1 = {1, 2, 3};
    subsetsWithBitmask(arr1);
    
    cout << "\n===== SUBSETS WITH RECURSION =====\n";
    current.clear();
    subsetsRecursive(arr1, 0);
    
    cout << "\n===== PERMUTATIONS WITH STL =====\n";
    vector<int> arr2 = {1, 2, 3};
    permutationsSTL(arr2);
    
    cout << "\n===== PERMUTATIONS WITH RECURSION =====\n";
    permutationsRecursive(arr2, 0);
    
    cout << "\n===== N-QUEENS (n=4) =====\n";
    nQueensSolutions = 0;
    queens.clear();
    solveNQueens(0, 4);
    cout << "Total solutions for 4-Queens: " << nQueensSolutions << "\n";
    
    cout << "\n===== SUBSET SUM =====\n";
    vector<int> nums = {3, 7, 1, 8, 2};
    cout << "Can make sum 11? " << (subsetSum(nums, 11) ? "Yes" : "No") << "\n";
    cout << "Can make sum 100? " << (subsetSum(nums, 100) ? "Yes" : "No") << "\n";
    
    cout << "\n===== MEET IN THE MIDDLE =====\n";
    cout << "Can make sum 11 (MITM)? " << (subsetSumMeetInMiddle(nums, 11) ? "Yes" : "No") << "\n";
    
    return 0;
}
