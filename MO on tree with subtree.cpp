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
const ll mod = 1e9+7;
// to get the number of color >= k
//////////////////////////////////////////////////////
const int N=100005,SQ=700;
int n,m,qu,in[N],out[N],tree[2*N],color[N],fnode[N],fcolor[N],timer=1,ans[N];vector<int>adj[N];
struct query{
    int l,r,k,idx;
}q[N];
void eulerTour(int node,int parent)
{
    in[node]=timer;
    tree[timer]=node;
    timer++;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            eulerTour(it,node);
        }
    }
    out[node]=timer;
    tree[timer]=node;
    timer++;
}
struct FenwickTree{
    int bit[100005]={};
    void update(int idx,int val)
    {
        if(idx==0)return;
        while(idx<100005)
        {
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }
    int query(int idx)
    {
        if(idx==0)return 0;
        int ret=0;
        while(idx>0)
        {
            ret+=bit[idx];
            idx-=idx&-idx;
        }
        return ret;
    }
}ff;
bool com(query a,query b)
{
    int x=a.l/SQ,y=b.l/SQ;
    if(x!=y)return x<y;
    if(x&1)return a.r<b.r;
    else return a.r>b.r;
}
void add(int idx)
{
    int node=tree[idx];
    fnode[node]++;
    if(fnode[node]==2)
    {
        fcolor[color[node]]++;
        ff.update(fcolor[color[node]],1);
        ff.update(fcolor[color[node]]-1,-1);
    }
}
void remove(int idx)
{
    int node=tree[idx];
    fnode[node]--;
    if(fnode[node]==1)
    {
        ff.update(fcolor[color[node]],-1);
        ff.update(fcolor[color[node]]-1,1);
        fcolor[color[node]]--;
    }
}
int get(int l,int r)
{
    return ff.query(r)-ff.query(l-1);
}
void MO_process()
{
    sort(q+1,q+1+qu,com);
    int l=1,r=0;
    for(int i=1;i<=qu;i++)
    {
        while(r<q[i].r)add(++r);
        while(r>q[i].r)remove(r--);
        while(l<q[i].l)remove(l++);
        while(l>q[i].l)add(--l);
        ans[q[i].idx]=get(q[i].k,n);
    }
}
void solve(){
   cin>>n>>qu;
    for(int i=1;i<=n;i++)
    {
        cin>>color[i];
    }
    m=n-1;
    while(m--)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    eulerTour(1,-1);
    for(int i=1;i<=qu;i++)
    {
        int a,k;cin>>a>>k;
        q[i].l=in[a];
        q[i].r=out[a];
        q[i].idx=i;
        q[i].k=k;
    }
    MO_process();
    for(int i=1;i<=qu;i++)
    {
        cout<<ans[i]<<'\n';
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
        cout << nl;
    }
    return 0;
}