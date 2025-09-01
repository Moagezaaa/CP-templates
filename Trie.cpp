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
struct BinaryTrie{
    struct Node{
        Node*ch[2];
        int frq[2];
        Node(){
            ch[0]=ch[1]=0;
            frq[0]=frq[1]=0;
        }
    };
    Node*root=new Node();
    void insert(int n)
    {
        Node*cur=root;
        for(int i=29;i>=0;i--)
        {
            bool idx=(n>>i)&1;
            if(cur->ch[idx]==0)
            {
                cur->ch[idx]=new Node();
            }
            cur->frq[idx]++;
            cur=cur->ch[idx];
        }
    }
    void del(int n,int i,Node*cur)
    {
        if(i==-1) return;
        bool idx=(n>>i)&1;
        del(n,i-1,cur->ch[idx]);
        cur->frq[idx]--;
        if(cur->frq[idx]==0)
        {
            delete cur->ch[idx];
            cur->ch[idx]=0;
        }
    }
    int mxXor(int n)
    {
        Node*cur=root;
        int ret=0;
        for(int i=29;i>=0;i--)
        {
            bool idx=(n>>i)&1;
            if(cur->ch[idx^1]==0)
            {
                cur=cur->ch[idx];
            }
            else
            {
                cur=cur->ch[idx^1];
                ret|=1<<i;
            }
        }
        return ret;
    }
};
void solve()
{
    BinaryTrie tr;
    int q;cin>>q;while(q--)
    {
        char op;cin>>op;
        int x;cin>>x;
        if(op=='+')
        {
            tr.insert(x);
        }
        else if(op=='-')
        {
            tr.del(x,29,tr.root);
        }
        else
        {
            cout<<tr.mxXor(x)<<'\n';
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