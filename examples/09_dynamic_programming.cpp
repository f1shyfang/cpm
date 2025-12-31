// Chapter 7: Dynamic Programming
// Break problem into overlapping subproblems, store results
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ===== FIBONACCI (Classic DP Example) =====
// Naive recursive: O(2^n)
ll fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

// Top-down with memoization: O(n)
map<int, ll> memo;
ll fibMemo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

// Bottom-up tabulation: O(n) time, O(n) space
ll fibBottomUp(int n) {
    if (n <= 1) return n;
    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space-optimized: O(n) time, O(1) space
ll fibOptimized(int n) {
    if (n <= 1) return n;
    ll prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        ll curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// ===== COIN CHANGE (Minimum Coins) =====
// Given coin denominations, find minimum coins to make amount
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != 1e9) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == 1e9 ? -1 : dp[amount];
}

// ===== COIN CHANGE (Count Ways) =====
// Count number of ways to make amount
ll countWays(vector<int>& coins, int amount) {
    vector<ll> dp(amount + 1, 0);
    dp[0] = 1;
    
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}

// ===== LONGEST INCREASING SUBSEQUENCE (LIS) =====
// O(n^2) approach
int lisQuadratic(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // dp[i] = LIS ending at index i
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

// O(n log n) approach using binary search
int lisNLogN(vector<int>& arr) {
    vector<int> tails;  // tails[i] = smallest tail of LIS of length i+1
    
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    
    return tails.size();
}

// ===== 0/1 KNAPSACK =====
// Select items (can't take fractions) to maximize value within weight limit
int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i-1][w];  // Don't take item i
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    return dp[n][capacity];
}

// Space-optimized knapsack: O(capacity) space
int knapsack01Optimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // IMPORTANT: iterate backwards to avoid using same item twice
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}

// ===== LONGEST COMMON SUBSEQUENCE (LCS) =====
int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}

// ===== EDIT DISTANCE (Levenshtein Distance) =====
int editDistance(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    // Base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i;  // Delete all
    for (int j = 0; j <= m; j++) dp[0][j] = j;  // Insert all
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // Delete
                    dp[i][j-1],    // Insert
                    dp[i-1][j-1]   // Replace
                });
            }
        }
    }
    
    return dp[n][m];
}

// ===== GRID PATHS =====
// Count paths from top-left to bottom-right (only right/down moves)
ll gridPaths(int n, int m) {
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    
    return dp[n-1][m-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "===== FIBONACCI =====\n";
    int n = 40;
    cout << "F(" << n << ") = " << fibOptimized(n) << "\n\n";
    
    cout << "===== COIN CHANGE (Minimum Coins) =====\n";
    vector<int> coins = {1, 5, 10, 25};
    int amount = 63;
    cout << "Minimum coins for " << amount << ": " << coinChange(coins, amount) << "\n\n";
    
    cout << "===== COIN CHANGE (Count Ways) =====\n";
    cout << "Ways to make " << amount << ": " << countWays(coins, amount) << "\n\n";
    
    cout << "===== LONGEST INCREASING SUBSEQUENCE =====\n";
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nLIS length: " << lisNLogN(arr) << "\n\n";
    
    cout << "===== 0/1 KNAPSACK =====\n";
    vector<int> weights = {1, 2, 3, 4, 5};
    vector<int> values = {1, 4, 8, 9, 11};
    int capacity = 8;
    cout << "Weights: "; for (int w : weights) cout << w << " "; cout << "\n";
    cout << "Values:  "; for (int v : values) cout << v << " "; cout << "\n";
    cout << "Capacity: " << capacity << "\n";
    cout << "Max value: " << knapsack01Optimized(weights, values, capacity) << "\n\n";
    
    cout << "===== LONGEST COMMON SUBSEQUENCE =====\n";
    string s1 = "ABCBDAB", s2 = "BDCABA";
    cout << "s1 = " << s1 << ", s2 = " << s2 << "\n";
    cout << "LCS length: " << lcs(s1, s2) << "\n\n";
    
    cout << "===== EDIT DISTANCE =====\n";
    string a = "kitten", b = "sitting";
    cout << "\"" << a << "\" -> \"" << b << "\"\n";
    cout << "Edit distance: " << editDistance(a, b) << "\n\n";
    
    cout << "===== GRID PATHS =====\n";
    int rows = 4, cols = 5;
    cout << "Paths in " << rows << "x" << cols << " grid: " << gridPaths(rows, cols) << "\n";
    
    return 0;
}

/*
DP Key Concepts:
1. Optimal Substructure: Solution to problem can be built from solutions to subproblems
2. Overlapping Subproblems: Same subproblems are solved multiple times

DP Approaches:
- Top-down (Memoization): Recursive with caching
- Bottom-up (Tabulation): Iterative, build table from base cases

DP Problem Types:
- Counting: How many ways?
- Optimization: Minimum/maximum value?
- Existence: Is it possible?

Common DP Patterns:
- 1D DP: dp[i] depends on previous states
- 2D DP: dp[i][j] for two parameters (strings, grids)
- Bitmask DP: dp[mask] for subset states
- Interval DP: dp[i][j] for ranges
*/
