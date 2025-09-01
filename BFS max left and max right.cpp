#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define nl "\n"
#define ull unsigned long long
#define rv return void
#define str string
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vec vector
#define fixed(n) fixed << setprecision(n)
using namespace std;
const int N=2e5+5;
ll n,q,s[N],T[N][22],Log[N];
vec<vec<int>>v(105,vector<int>());
 map<int,int>m;
ll merge(ll a,ll b)
{
    return max(a,b);
}
void build()
{
    for(int i=0;i<n;i++)
    {
        T[i][0]=s[i];
    }
    for(int pw=1;(1<<pw)<=n;pw++) 
    {
        for(int i=0;i+(1<<pw)<=n;i++)
        {
            T[i][pw]=merge(T[i][pw-1],T[i+(1<<(pw-1))][pw-1]);
        }
    }
}
ll query(int l,int r)
{
    if(r<l)
    {
        return INT_MIN;
    }
    int sz=r-l+1;
    ll ret=INT_MIN;
    for(int i=0;i<22;i++)
    {
        if((sz>>i)&1)
        {
            return merge(query(l+(1<<i),r),T[l][i]);
        }
    }
    return ret;
}
ll query2(int l,int r)
{
    int sz=r-l+1;
    int pw=Log[sz];
    return merge(T[l][pw],T[r-(1<<pw)+1][pw]);
}
void preCount()
{
    Log[1]=0;
    for(int i=2;i<N;i++)
    {
        Log[i]=Log[i>>1]+1;
    }
}
void buildTree(int l, int r) {
    if (l>r) return;
    ll w = query(l, r);
    int p=m[w]; 
   if(p>l)v[w].push_back(query(l, p-1));
   if(p<r)v[w].push_back(query(p+1, r));
    buildTree(l, p-1);  
    buildTree(p+1, r);  
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
       m.clear();
       v.assign(105, vector<int>());
    preCount();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        m[s[i]]=i;
    }
    build();
        buildTree(0, n-1);
        ll k=query(0, n-1);
        map<int,int>mm;
        queue<pair<int, int>> qq; 
        qq.push({k, 0});  
        while (!qq.empty()) {
            int node = qq.front().first;
            int lvl = qq.front().second;
            qq.pop();
            mm[node] = lvl;  
            for (int i = 0;i<v[node].size();i++) {
                qq.push({v[node][i],lvl + 1}); 
            }
        }
        for (int i = 0; i < n; i++) cout << mm[s[i]] << " ";  
        cout<<nl;
    }
    return 0;
}