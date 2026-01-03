// Chapter 21: Number Theory Basics
// Essential math for competitive programming
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ===== PRIME NUMBERS =====

// Check if n is prime: O(sqrt(n))
bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Sieve of Eratosthenes: Find all primes up to n
// O(n log log n)
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Get list of primes up to n
vector<int> getPrimes(int n) {
    vector<bool> is_prime = sieve(n);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

// Prime factorization: O(sqrt(n))
map<ll, int> primeFactors(ll n) {
    map<ll, int> factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

// ===== GCD AND LCM =====

// Euclidean GCD: O(log(min(a,b)))
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Or use __gcd(a, b) from <algorithm>

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;  // Avoid overflow
}

// Extended Euclidean Algorithm
// Find x, y such that ax + by = gcd(a, b)
ll extendedGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// ===== MODULAR ARITHMETIC =====

const ll MOD = 1e9 + 7;

// (a + b) % m
ll modAdd(ll a, ll b, ll m = MOD) {
    return ((a % m) + (b % m)) % m;
}

// (a - b) % m (handle negative)
ll modSub(ll a, ll b, ll m = MOD) {
    return ((a % m) - (b % m) + m) % m;
}

// (a * b) % m
ll modMul(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
}

// Fast exponentiation: a^b % m in O(log b)
ll modPow(ll a, ll b, ll m = MOD) {
    ll result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) result = modMul(result, a, m);
        a = modMul(a, a, m);
        b >>= 1;
    }
    return result;
}

// Modular inverse: a^(-1) mod m
// Only works when gcd(a, m) = 1
// Using Fermat's little theorem (m must be prime)
ll modInverse(ll a, ll m = MOD) {
    return modPow(a, m - 2, m);
}

// Modular division: (a / b) % m = (a * b^(-1)) % m
ll modDiv(ll a, ll b, ll m = MOD) {
    return modMul(a, modInverse(b, m), m);
}

// ===== COMBINATORICS =====

// Precompute factorials for nCr
const int MAXN = 1e6;
vector<ll> fact(MAXN + 1), inv_fact(MAXN + 1);

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = modMul(fact[i-1], i);
    }
    inv_fact[MAXN] = modInverse(fact[MAXN]);
    for (int i = MAXN - 1; i >= 0; i--) {
        inv_fact[i] = modMul(inv_fact[i+1], i + 1);
    }
}

// nCr mod p
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return modMul(fact[n], modMul(inv_fact[r], inv_fact[n-r]));
}

// nPr mod p
ll nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return modMul(fact[n], inv_fact[n-r]);
}

// ===== EULER'S TOTIENT FUNCTION =====
// φ(n) = count of numbers in [1,n] coprime to n
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "===== PRIME CHECKING =====\n";
    vector<int> test = {1, 2, 17, 18, 97, 100};
    for (int n : test) {
        cout << n << " is " << (isPrime(n) ? "prime" : "not prime") << "\n";
    }
    cout << "\n";
    
    cout << "===== SIEVE OF ERATOSTHENES =====\n";
    vector<int> primes = getPrimes(50);
    cout << "Primes up to 50: ";
    for (int p : primes) cout << p << " ";
    cout << "\n\n";
    
    cout << "===== PRIME FACTORIZATION =====\n";
    ll n = 360;
    cout << n << " = ";
    auto factors = primeFactors(n);
    bool first = true;
    for (auto& [p, e] : factors) {
        if (!first) cout << " × ";
        cout << p << "^" << e;
        first = false;
    }
    cout << "\n\n";
    
    cout << "===== GCD AND LCM =====\n";
    ll a = 48, b = 18;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << "\n";
    cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << "\n\n";
    
    cout << "===== EXTENDED GCD =====\n";
    ll x, y;
    ll g = extendedGcd(a, b, x, y);
    cout << a << " × " << x << " + " << b << " × " << y << " = " << g << "\n\n";
    
    cout << "===== MODULAR ARITHMETIC =====\n";
    ll big = 1e18;
    cout << "10^18 mod (10^9+7) = " << (big % MOD) << "\n";
    cout << "2^1000 mod (10^9+7) = " << modPow(2, 1000) << "\n";
    cout << "Inverse of 3 mod (10^9+7) = " << modInverse(3) << "\n";
    cout << "Verify: 3 × " << modInverse(3) << " mod (10^9+7) = " << modMul(3, modInverse(3)) << "\n\n";
    
    cout << "===== COMBINATIONS =====\n";
    precomputeFactorials();
    cout << "10! = " << fact[10] << "\n";
    cout << "C(10, 3) = " << nCr(10, 3) << "\n";
    cout << "P(10, 3) = " << nPr(10, 3) << "\n\n";
    
    cout << "===== EULER'S TOTIENT =====\n";
    for (int i = 1; i <= 12; i++) {
        cout << "φ(" << i << ") = " << phi(i) << "\n";
    }
    
    return 0;
}

/*
Key Formulas:

GCD/LCM:
- gcd(a, b) × lcm(a, b) = a × b
- gcd(a, 0) = a

Modular Arithmetic:
- (a + b) mod m = ((a mod m) + (b mod m)) mod m
- (a × b) mod m = ((a mod m) × (b mod m)) mod m
- a^(-1) mod p = a^(p-2) mod p  (Fermat's theorem, p prime)

Euler's Totient:
- φ(p) = p - 1 for prime p
- φ(p^k) = p^(k-1) × (p - 1)
- φ(a × b) = φ(a) × φ(b) if gcd(a,b) = 1
- a^φ(m) ≡ 1 (mod m) if gcd(a,m) = 1 (Euler's theorem)

Useful Identities:
- Sum of divisors: σ(n) = Π (p^(e+1) - 1)/(p - 1)
- Count of divisors: τ(n) = Π (e + 1)
*/
