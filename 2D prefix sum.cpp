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
const ll mod = 1e9,nn=1005;
void solve(){
 ll n,q;cin>>n>>q;
 vec<vec<ll>>v(nn,vec<ll>(nn,0)),p(nn,vec<ll>(nn,0));
 for(int i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    v[x][y]+=x*y;
 }
 for(int i=1;i<nn;i++){
    for(int j=1;j<nn;j++)p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+v[i][j];
 }
 while(q--){
    int x,y,xx,yy;cin>>x>>y>>xx>>yy;
    cout<<p[xx-1][yy-1]-p[xx-1][y]-p[x][yy-1]+p[x][y]<<nl;
 }
}
int main()
{
   Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}