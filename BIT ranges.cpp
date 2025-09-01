#include <bits/stdc++.h>
#define ll long long 
#define int long long
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
const ll mod = 1e9+7,n=105;
//////////////////////////////////////////////////////
template < typename T = int > struct BIT {
    
    int N;
    T DEFAULT;
    vector < T > M, C;

    BIT(int sz = 0){
        N = sz + 1, DEFAULT = 0;
        M = C = vector < T > (N + 10);
    }

    int lowest_bit(int idx){
        return (idx & -idx);
    }

    void build(vector < T >& nums){
        for(int i = 0; i < (nums).size(); i++)
            add(i, i, nums[i]);
    }

    void add_range(int idx, T addM, T addC){
        idx++;
        while(idx <= N){
            M[idx] += addM;
            C[idx] += addC;
            idx += lowest_bit(idx);
        }
    }

    void add(int l, int r, T val) {
        add_range(l, val, -val * (l - 1));
        add_range(r + 1, -val, val * r);
    }

    void add(int idx, T val){
        add(idx, idx, val);
    }

    T get(int idx){
        T ans = DEFAULT;
        int pos = idx++;
        while(idx){
            ans += pos * M[idx] + C[idx];
            idx -= lowest_bit(idx);
        }
        return ans;
    }

    T query(int L, int R){
        if(L > R) return DEFAULT;
        return get(R) - get(L - 1);
    }
};

void solve(){
   int a,b;cin>>a>>b;
    BIT p(a+5);
   vec<int>v(a);
   for(int i=0;i<a;i++)cin>>v[i];
   p.build(v);
   while(b--){
    int x;cin>>x;
    if(x==1){
        int y,z,l;cin>>y>>z>>l;y--;z--;
        p.add(y,z,l);
    }
    else {
        int y;cin>>y;
        cout<<p.query(y-1,y-1)<<nl;
    }
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