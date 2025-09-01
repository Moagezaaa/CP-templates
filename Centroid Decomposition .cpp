#include <bits/stdc++.h>
#define ll  long long 
// #define int  long long 
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
// const ll mod = 1e9+7;
const int N=2e5+5;
int n,k,sz[N],f[N],mx_dep;vector<int>adj[N];bool vis[N];ll ans;
void dfsSZ(int node,int par)
{
    sz[node]=1;
    for(auto it:adj[node])
    {
        if(it!=par&&!vis[it])
        {
            dfsSZ(it,node);
            sz[node]+=sz[it];
        }
    }
}
int findCentroid(int node,int par,int size)
{
    for(auto it:adj[node])
    {
        if(it!=par&&!vis[it]&&sz[it]>size/2)
        {
            return findCentroid(it,node,size);
        }
    }
    return node;
}
void get(int node,int par,int dep)
{
    if(dep>k) return;
    ans+=f[k-dep];
    for(auto it:adj[node])
    {
        if(it!=par&&!vis[it])
        {
            get(it,node,dep+1);
        }
    }
}
void fill(int node,int par,int dep)
{
    if(dep>k) return;
    f[dep]++;
    mx_dep=max(mx_dep,dep);
    for(auto it:adj[node])
    {
        if(it!=par&&!vis[it])
        {
            fill(it,node,dep+1);
        }
    }
}
void initCentroid(int node,int par)
{
    dfsSZ(node,0);
    int centroid=findCentroid(node,0,sz[node]);
    vis[centroid]=1;
    mx_dep=0;
    for(auto it:adj[centroid])
    {
        if(!vis[it])
        {
            get(it,centroid,1);
            fill(it,centroid,1);
        }
    }
    for(int i=1;i<=mx_dep;i++)
    {
        f[i]=0;
    }
    for(auto it:adj[centroid])
    {
        if(!vis[it])
        {
            initCentroid(it,centroid);
        }
    }
}
///////////////////////////////////////////////////////
void solve() {
   cin>>n>>k;
  for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    f[0]=1;
    initCentroid(1,0);
    cout<<ans;
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