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
#define Moageza ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
const ll mod = 1e9+7;
struct coordinateCopmression{
private:
    vector<ll>init;
    void compress(vector<ll>&v)
    {
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    }
public:
    coordinateCopmression(vector<ll>&v)
    {
        init=v;
        compress(init);
    }
    int index(ll val)
    {
        return lower_bound(init.begin(),init.end(),val)-init.begin();
    }
    ll initVal(int idx)
    {
        return init[idx];
    }
};
void solve() {
    int a;cin>>a;
    vec<ll>x(a);
    vec<ll>v,l(2*a+5,0);
    for(int i=0;i<a;i++)cin>>x[i];
    coordinateCopmression c(x);
    for(int i=0;i<a;i++){
        x[i]=c.index(x[i]);
    }
}
signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout <<nl;
    }
    
    return 0;
}