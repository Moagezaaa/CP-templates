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
#define Moageza ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
const ll mod = 1e9+7;
const int N=2e5+5;
const int Qu=2e5+5;
const int SQ=488;
struct Query{
    int l,r,q_idx,blk_idx;
    Query(){}
    Query(int _l,int _r,int _q_idx)
    {
        l=_l,r=_r,q_idx=_q_idx,blk_idx=_l/SQ;
    }
    bool operator<(const Query&Q)const{
        if(blk_idx!=Q.blk_idx)
        {
            return blk_idx<Q.blk_idx;
        }
        return r<Q.r;
    }
};
ll n,q,arr[N],frq[1000006],res=0,ans[Qu];Query qu[Qu];
void add(int idx)
{
   if(!frq[arr[idx]])res++;
   frq[arr[idx]]++;
}
void remove(int idx)
{
    frq[arr[idx]]--;
    if(!frq[arr[idx]])res--;
}
void MO_process()
{
    sort(qu,qu+q);
    int l=1,r=0;
    for(int i=0;i<q;i++)
    {
        while(l<qu[i].l) remove(l++);
        while(l>qu[i].l) add(--l);
        while(r<qu[i].r) add(++r);
        while(r>qu[i].r) remove(r--);
        // If I need to get  minimal x such that x occurs in the interval l r strictly more than ((r-l+1)/k) 
 	    // int x=80,y,p=1e9;
        // while(x--){
        //     int  y=arr[rng()%(r-l+1)+l];
        //     if(frq[y]>(r-l+1)/qu[i].kk)p=min(p,y);
        // }
        // if(p==1e9)p=-1;
        ans[qu[i].q_idx]=res;
    }
}
void solve() {
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<q;i++)
    {
        int l,r;cin>>l>>r;
        qu[i]=Query(--l,--r,i);
    }
    MO_process();
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<'\n';
    }
}
signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout <<nl;
    }
    
    return 0;
}