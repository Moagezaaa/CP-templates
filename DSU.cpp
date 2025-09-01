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
const ll mod = 1e9+7,n=105;
//////////////////////////////////////////////////////
template < typename T = ll, int Base = 0 > struct DSU {
    
    vector < T > parent, Gsize,cost;
    // stack<array<int,4>>st;
    DSU(int MaxNodes){
       cost= parent = Gsize  = vector < T > (MaxNodes + Base);
        for(int i = Base; i < MaxNodes + Base; i++){
            parent[i] = i;
             Gsize[i] = 1;
        }
    }
    
    T find_leader(T i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return find_leader(parent[i]);
    }
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if(Gsize[leader_u] < Gsize[leader_v]) 
            swap(leader_u, leader_v);
        //      array<int,4>p={0,0,0,0};
        // p[0]=leader2,p[1]=group[leader2];
        // p[2]=leader1,p[3]=parent[leader1];
        // st.push(p);
        if(leader_u == leader_v) return;
        Gsize[leader_u] += Gsize[leader_v];
        cost[leader_v] -= cost[leader_u];
        parent[leader_v] = leader_u;
    }
    int get_size(int u){
        return Gsize[find_leader(u)];
    }
     void rollBack()
    {
        if(st.empty())return;
        auto &[a,b,c,d]=st.top();
        st.pop();
        group[a]=b;
        parent[c]=d;
    }
};
// struct edge{
//     int u,v,w;
//     bool operator<(const edge&d)const{
//        return w<d.w;
//     }
//    };
void solve(){
    ll a,b,c;cin >> a>>b;
  DSU<ll>d(a+5);
  
}
int main()
{
   Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}