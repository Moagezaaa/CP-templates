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
struct Trie{
     struct Node{
        Node*child[26];
        int frq[26];
        int IsEnd,Prefix;
        Node(){
            memset(child,0,sizeof child);
            memset(frq,0,sizeof frq);
            IsEnd=Prefix=0;
        }
    };
    Node*root=new Node();
    void insert(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)
            {
                cur->child[idx]=new Node();
            }
            cur=cur->child[idx];
             cur->frq[idx]++;
            cur->Prefix++;
        }
        cur->IsEnd++;
    }
    bool SearchWord(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->IsEnd;
    }
    int CountWord(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->IsEnd;
    }
    int CountPrefix(string &s)
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->Prefix;
    }
};
void solve(){
   int a,b;cin>>a>>b;
   Trie t;
   for(int i=0;i<a;i++){
    str x;cin>>x;
    t.insert(x);
   }
   for(int i=0;i<b;i++){
    str x;cin>>x;
    cout<<t.CountPrefix(x)<<nl;
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