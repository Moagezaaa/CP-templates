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
struct SegmentTree{
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
    ll sz,skip=LLONG_MAX;
    vector<ll>seg,lazy;
    void propegate(int l,int r,int node)
    {
        if(lazy[node]==0)return;
        if(l!=r)
        {
            lazy[L]+=lazy[node];
            lazy[R]+=lazy[node];

        }
   // sum ->seg[node] += lazy[node] * (r - l + 1);
        seg[node]+=lazy[node];
        lazy[node]=0;
    }
    void update(int l,int r,int node,int lx,int rx,ll val)
    {
        propegate(l,r,node);
        if(l>rx||r<lx)
        {
            return;
        }
        if(l>=lx&&r<=rx)
        {
            lazy[node]+=val;
            propegate(l,r,node);
            return;
        }
        update(l,mid,L,lx,rx,val);
        update(mid+1,r,R,lx,rx,val);
        seg[node]=min(seg[L],seg[R]);
    }
    ll query(int l,int r,int node,int lx,int rx)
    {
        propegate(l,r,node);
        if(l>=lx&&r<=rx)
        {
            return seg[node];
        }
        if(l>rx||r<lx)
        {
            return skip;
        }
	// if I move right or left
	// propegate(l,mid,L);
        // propegate(mid+1,r,R);
        return min(query(l,mid,L,lx,rx),query(mid+1,r,R,lx,rx));
    }
public:
    SegmentTree(int n){
        sz=1;
        while(sz<n)sz*=2;
        seg=vector<ll>(sz*2,0);
        lazy=vector<ll>(sz*2,0);
    }
    void update(int l,int r,ll val)
    {
        update(0,sz-1,0,l,r,val);
    }
    ll query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
};
void solve(){
  int n,q;cin>>n>>q;
    SegmentTree st(n);
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            ll l,r,val;cin>>l>>r>>val;
            st.update(l,r-1,val);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<st.query(l,r-1)<<nl;
        }
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