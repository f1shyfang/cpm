// Example 5: Common Competitive Programming Patterns
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // ===== PATTERN 1: Multiple Test Cases =====
    /*
    int t;
    cin >> t;
    while (t--) {
        // solve each test case
    }
    */
    
    // ===== PATTERN 2: Read n elements =====
    cout << "=== Reading Array ===\n";
    cout << "Enter n and n elements: ";
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    
    cout << "You entered: ";
    for (int x : a) cout << x << " ";
    cout << "\n\n";
    
    // ===== PATTERN 3: Frequency Count =====
    cout << "=== Frequency Count ===\n";
    map<int, int> freq;
    for (int x : a) {
        freq[x]++;
    }
    cout << "Frequencies:\n";
    for (auto &[val, cnt] : freq) {
        cout << val << " appears " << cnt << " times\n";
    }
    cout << "\n";
    
    // ===== PATTERN 4: Prefix Sum =====
    cout << "=== Prefix Sum ===\n";
    vi prefix(n + 1, 0);
    rep(i, n) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    cout << "Prefix sums: ";
    rep(i, n + 1) cout << prefix[i] << " ";
    cout << "\n";
    
    // Query: sum of range [l, r] (0-indexed)
    int l = 0, r = n - 1;
    cout << "Sum of range [" << l << ", " << r << "] = " << prefix[r + 1] - prefix[l] << "\n\n";
    
    // ===== PATTERN 5: Two Pointers (find pair with given sum) =====
    cout << "=== Two Pointers ===\n";
    vi sorted_a = a;
    sort(all(sorted_a));
    
    cout << "Enter target sum: ";
    int target;
    cin >> target;
    
    int left = 0, right = n - 1;
    bool found = false;
    while (left < right) {
        int sum = sorted_a[left] + sorted_a[right];
        if (sum == target) {
            cout << "Found pair: " << sorted_a[left] << " + " << sorted_a[right] << " = " << target << "\n";
            found = true;
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    if (!found) cout << "No pair found\n";
    cout << "\n";
    
    // ===== PATTERN 6: Binary Search Answer =====
    cout << "=== Binary Search on Answer ===\n";
    // Example: find smallest x such that x*x >= n
    auto check = [&](int x) { return (ll)x * x >= n; };
    
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << "Smallest x where x*x >= " << n << " is " << lo << "\n\n";
    
    // ===== PATTERN 7: GCD / LCM =====
    cout << "=== GCD / LCM ===\n";
    int x = 12, y = 18;
    cout << "GCD(" << x << ", " << y << ") = " << __gcd(x, y) << "\n";
    cout << "LCM(" << x << ", " << y << ") = " << (ll)x * y / __gcd(x, y) << "\n\n";
    
    // ===== PATTERN 8: Modular Arithmetic =====
    cout << "=== Modular Arithmetic ===\n";
    const int MOD = 1e9 + 7;
    ll big1 = 1e9, big2 = 1e9;
    ll result = (big1 % MOD * big2 % MOD) % MOD;
    cout << "(" << big1 << " * " << big2 << ") % MOD = " << result << "\n";
    
    return 0;
}

/*
Sample Input:
5
3 1 4 1 5
8

To compile and run:
    g++ 05_common_patterns.cpp -o 05_common_patterns
    ./05_common_patterns
*/
