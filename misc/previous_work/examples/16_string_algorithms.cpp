// String algorithms: prefix function (KMP), Z-function, pattern search
#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> kmpSearch(const string& text, const string& pat) {
    string combined = pat + '#' + text;
    vector<int> pi = prefixFunction(combined);
    vector<int> pos;
    int m = pat.size();
    for (int i = m + 1; i < (int)combined.size(); i++) {
        if (pi[i] == m) pos.push_back(i - 2 * m);
    }
    return pos;
}

vector<int> zSearch(const string& text, const string& pat) {
    string combined = pat + '#' + text;
    vector<int> z = zFunction(combined);
    vector<int> pos;
    int m = pat.size();
    for (int i = m + 1; i < (int)combined.size(); i++) {
        if (z[i] >= m) pos.push_back(i - m - 1);
    }
    return pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text = "ababaabababa";
    string pat = "aba";

    cout << "Text: " << text << "\nPattern: " << pat << "\n\n";

    cout << "=== Prefix Function (KMP) ===\n";
    auto pi = prefixFunction(text);
    cout << "pi: "; for (int x : pi) cout << x << " "; cout << "\n\n";

    cout << "=== KMP Search ===\n";
    auto pos1 = kmpSearch(text, pat);
    cout << "Matches at: "; for (int p : pos1) cout << p << " "; cout << "\n\n";

    cout << "=== Z-Function ===\n";
    auto z = zFunction(text);
    cout << "z:  "; for (int x : z) cout << x << " "; cout << "\n\n";

    cout << "=== Z Search ===\n";
    auto pos2 = zSearch(text, pat);
    cout << "Matches at: "; for (int p : pos2) cout << p << " "; cout << "\n";

    return 0;
}
