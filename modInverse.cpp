#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define nl "\n"
#define ull unsigned long long
#define pb push_back
#define rv return void
#define str string
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vec vector
#define fixed(n) fixed << setprecision(n)
#define Moageza ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
///////////////////////////////////////////////////////

ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
void solve() {
 ll a,mod=1e9+7,c=0,y=0;cin >> a;
 vec<ll>v(a);
 for(int i = 0; i <a; i++)cin >> v[i];
 vec<ll>x=v;
 for(int i=1;i <a; i++)v[i]+=v[i-1];
 c=v.back();
 for(int i=0;i<a-1;i++){
        y+=((((c-v[i]+mod))%mod)*x[i])%mod;
        y%=mod;
        // cout<<y<<" "<<' '<<((c-v[i]))<<nl;
    }
    //  cout<<y<<" ";
   y%=mod;
//  cout<<(y/a);
   ll w= (a*(a-1)/2)%mod; 
    ll h=modInverse(w, mod);
    ll ans=(y*h)%mod;
    cout <<ans;
}
int main() {
    Moageza
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}
