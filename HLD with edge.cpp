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
//////////////////////////////////////////////////////
struct SegmentTree{
    private:
    #define L 2*node+1
    #define R 2*node+2
    #define mid (l+r>>1)
      ll merge(ll x,ll y){
        return max(x,y);
      }
      ll merge2(ll x,ll y){
        return min(x,y);
      }
        int sz;vector<ll>seg;vector<ll>seg2;
        void update(int l,int r,int node,int idx,ll val)
        {
            if(l==r)
            {
                seg[node]=val;
                seg2[node]=val;
                return;
            }
            if(idx<=mid)
            {
                update(l,mid,L,idx,val);
            }
            else
            {
                update(mid+1,r,R,idx,val);
            }
            seg[node]=merge(seg[L],seg[R]);
            seg2[node]=merge2(seg2[L],seg2[R]);
        }
        ll query(int l,int r,int node,int lq,int rq)
        {
            if(r<lq||l>rq)
            {
                return -1;
            }
            if(l>=lq&&r<=rq)
            {
                return seg[node];
            }
            ll lft=query(l,mid,L,lq,rq);
            ll rgt=query(mid+1,r,R,lq,rq);
            return merge(lft,rgt);
        }
        ll query2(int l,int r,int node,int lq,int rq)
        {
            if(r<lq||l>rq)
            {
                return INT_MAX;
            }
            if(l>=lq&&r<=rq)
            {
                return seg2[node];
            }
            ll lft=query2(l,mid,L,lq,rq);
            ll rgt=query2(mid+1,r,R,lq,rq);
            return merge2(lft,rgt);
        }
    public:
        SegmentTree(int n)
        {
            sz=1;
            while(sz<n) sz*=2;
            seg=vector<ll>(sz*2);
            seg2=vector<ll>(sz*2);
        }
        void update(int idx,ll val)
        {
            update(0,sz-1,0,idx,val);
        }
        ll query(int l,int r)
        {
            return query(0,sz-1,0,l,r);
        }
        ll query2(int l,int r)
        {
            return query2(0,sz-1,0,l,r);
        }
    };
    template <typename T = int, bool VAL_ON_EDGE = true>
    class HLD {
    public:
        const vector<vector<int>> &adj;
        vector<int> dep, par, root, pos, SubtreeSz, child;
        int nxtPos;
    
        HLD(int n, const vector<vector<int>> &G, int treeRoot = 1)
            : adj(G), dep(n + 1), par(n + 1), root(n + 1), pos(n + 1), SubtreeSz(n + 1), child(n + 1, -1), nxtPos(1) {
            init(treeRoot);
            build(treeRoot);
        }
    
        void init(int u, int p = -1, int d = 0) {
            dep[u] = d;
            par[u] = p;
            SubtreeSz[u] = 1;
            for (auto &v : adj[u]) {
                if (v == p) continue;
                init(v, u, d + 1);
                SubtreeSz[u] += SubtreeSz[v];
                if (child[u] == -1 || SubtreeSz[v] > SubtreeSz[child[u]])
                    child[u] = v;
            }
        }
    
        void build(int u, bool newChain = true) {
            root[u] = newChain ? u : root[par[u]];
            pos[u] = nxtPos++;
            if (child[u] != -1) build(child[u], false);
            for (auto &v : adj[u]) {
                if (v == par[u] || v == child[u]) continue;
                build(v, true);
            }
        }
    
        vector<pair<int, int>> queryPath(int u, int v) {
            vector<pair<int, int>> ret;
            while (root[u] != root[v]) {
                if (dep[root[u]] < dep[root[v]]) swap(u, v);
                ret.emplace_back(pos[root[u]], pos[u]);
                u = par[root[u]];
            }
            if (dep[u] > dep[v]) swap(u, v);
            if (!VAL_ON_EDGE) ret.emplace_back(pos[u], pos[v]);
            else if (u != v) ret.emplace_back(pos[u] + 1, pos[v]);
            return ret;
        }
        int getChild(int u, int v) {
            if (par[u] == v) return u;
            return v;
        }
    };

void solve(){
 int a,b;cin >> a;
 vec<vec<int>>p(a+1);
 vec<vec<int>>o(a+1);
 for(int i=1;i<a;i++){
    int x,y,z;cin >> x>>y>>z;
    p[x].push_back(y);p[y].push_back(x);
    o[i].push_back(x);o[i].push_back(y);o[i].push_back(z);
 }
 HLD<int, true> h(a,p);
 SegmentTree st(a+1);
 for(int i=1;i<a;i++){
    st.update(h.pos[h.getChild(o[i][0],o[i][1])]-1,o[i][2]);
 }
  cin>>b;
//   for(int i=1;i<=a;i++)cout<<st.query(i-1,i-1)<<" ";
 while(b--){
    int x,y;cin >> x>>y;
    vec<pair<int,int>>l=h.queryPath(x,y);
    ll c=0,d=INT_MAX;
    for(int i=0;i<l.size();i++){
        // cout<<l[i].first<<" "<<l[i].second<<endl;
        c=max(c,st.query(l[i].first-1,l[i].second-1));
        d=min(d,st.query2(l[i].first-1,l[i].second-1));

    }
    cout<<d<<" "<<c<<nl;
}
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
        cout << nl;
    }
    return 0;
}