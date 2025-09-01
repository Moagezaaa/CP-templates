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
const ll mod = 1e9+7,N=2e5+5;
//////////////////////////////////////////////////////
std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
ll rand(ll l,ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
struct node {
    ll a,b,c,d,e;
    node():a(0),b(0),c(0),d(0),e(0){}
    node(ll x,ll xx,ll xxx,ll xxxx,ll xxxxx):a(x),b(xx),c(xxx),d(xxxx),e(xxxxx){}
    
    node operator+(const node&x) const {
        return node(a+x.a, b+x.b, c+x.c, d+x.d, e+x.e);
    }

    node operator-(const node&x) const {
        return node(a-x.a, b-x.b, c-x.c, d-x.d, e-x.e);
    }

    bool operator==(const node&x) const {
        return a==x.a && b==x.b && c==x.c && d==x.d && e==x.e;
    }

    void operator+=(const node&x){
        a+=x.a; b+=x.b; c+=x.c; d+=x.d; e+=x.e;
    }

    void operator-=(const node&x){
        a-=x.a; b-=x.b; c-=x.c; d-=x.d; e-=x.e;
    }

    node operator=(const node&x){
        a=x.a; b=x.b; c=x.c; d=x.d; e=x.e;
        return *this;
    }
};
int s[N];
node f[N],per[N];
void init()
{
    for(int i=1;i<N;i++) f[i]=node(rand(1,1e9),rand(1,1e9),rand(1,1e9),rand(1,1e9),rand(1,1e9));
    // for(int i=2;i<N;i++) per[i]+=per[i-1];
}
void solve(){
     init();
	 int n,q;cin>>n>>q;
        node x[n+5],y[n+5];
        x[0]=node(0,0,0,0,0);
        y[0]=node(0,0,0,0,0);
        for(int i=1;i<=n;i++){
            int p;cin>>p;
            x[i]=f[p];
        }
        for(int i=1;i<=n;i++){
            int p;cin>>p;
            y[i]=f[p];
        }
        for(int i=2;i<=n;i++) x[i]+=x[i-1],y[i]+=y[i-1];
        while(q--){
            int l,r,L,R;cin>>l>>r>>L>>R;
           if(x[r]-x[l-1]==y[R]-y[L-1])cout<<"Yes";
           else cout<<"No";
           cout<<nl;
        }
}
signed main()
{
   Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}