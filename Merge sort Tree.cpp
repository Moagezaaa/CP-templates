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
// const ll mod = 1e9+7;
//////////////////////////////////////////////////////
struct MergeSortSegmentTree{
private:
    vector<vector<int>>seg;int sz,skip=0;
    void merge(vector<int>&ret,vector<int>&a,vector<int>&b)
    {     
        int l=0,r=0;
        ret.reserve(a.size()+b.size());
        while(l<a.size()&&r<b.size())
        {
            if(a[l]<b[r])
            {
                ret.push_back(a[l++]);;
            }
            else
            {
                ret.push_back(b[r++]);
            }
        }
        while(l<a.size())ret.push_back(a[l++]);
        while(r<b.size())ret.push_back(b[r++]);
    }
    void build(vector<int>&s,int l,int r,int node)
    {
        if(l==r)
        {
            if(l<s.size())
            {
                seg[node]={s[l]};
            }
            return;
        }
        int mid=l+r>>1;
        build(s,l,mid,2*node+1);
        build(s,mid+1,r,2*node+2);
        merge(seg[node],seg[2*node+1],seg[2*node+2]);
    }
    int query(int l,int r,int node,int lx,int rx,int k)
    {
        if(l>rx||r<lx)
        {
            return skip;
        }
        if(l>=lx&&r<=rx)
        {
            return seg[node].end()-upper_bound(seg[node].begin(),seg[node].end(),k);
        }
        int mid=l+r>>1;
        return query(l,mid,2*node+1,lx,rx,k)+query(mid+1,r,2*node+2,lx,rx,k);
    }
public:
    MergeSortSegmentTree(vector<int>&s){
        sz=1;
        while(sz<s.size())sz*=2;
        seg=vector<vector<int>>(sz*2);
        build(s,0,sz-1,0);
    }
    int query(int l,int r,int val)
    {
        return query(0,sz-1,0,l,r,val);
    }
};
void solve(){
    int a;cin>>a;
    vec<int>v(a);
    for(int i=0;i<a;i++)cin>>v[i];
    MergeSortSegmentTree s(v);
    int q;cin>>q;
    while(q--)
    {
        int l,r,k;cin>>l>>r>>k;
        l--;r--;
        cout<<s.query(l,r,k)<<nl;
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