#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define nl "\n"
#define ull unsigned long long
#define rv return void
#define str string
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vec vector
#define fixed(n) fixed << setprecision(n)
#define Moageza ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
const ll mod = 1e9+7,N=1e6+5;
ll fact[N], invFact[N];
// Fast Power Function (Modular Exponentiation)
ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
// Compute Factorials and Modular Inverses
void precompute() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;
    invFact[N - 1] = power(fact[N - 1], mod - 2, mod);
    for (ll i = N - 2; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
}
 
// Compute nCr % mod using Precomputed Factorials
ll nCr(ll n, ll r) {
    if (r > n || n < 0 || r < 0) return 0;
    return ((fact[n] * invFact[r]) % mod * invFact[n - r]) % mod;
}
void solve() {
  
}
signed main() {
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
    precompute();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}
