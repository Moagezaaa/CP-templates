#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define nl "\n"
#define ull unsigned long long
#define pb push_back
#define rv return void
#define str string
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vec vector
#define fixed(n) fixed << setprecision(n)
#define Moageza ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
const ll mod = 1e9+7,N=2e5+5;;
///////////////////////////////////////////////////////
ll a,b;
vector<pair<ll,ll>>adj[N];vector<ll>cost(N,-1);vector<ll>vis(N,-1);
void dijkstra(ll start)
{
    priority_queue<pair<ll,ll>,deque<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,start});
    cost[start]=0;
    while(pq.size())
    {
        pair<ll,ll>p=pq.top();
        pq.pop();
        ll node=p.second,nodecost=p.first;
          if(node==a)return;
        for(auto [node2,cost2]:adj[node])
        {
            if(cost[node2]==-1||nodecost+cost2<cost[node2]){pq.push({nodecost+cost2,node2});cost[node2]=nodecost+cost2;vis[node2]=node;}
        }
    }
}
void solve() {
 cin >> a >> b;
 for(int i=0;i<b;i++){
  ll x,y,z;cin>>x>>y;
  adj[x].push_back({y,1});
  adj[y].push_back({x,1});
 }
 dijkstra(1);
 vec<ll>ans;
 if(!(~cost[a]))rv(cout<<"IMPOSSIBLE");
 for(int i=a;~i;i=vis[i])ans.push_back(i);
 reverse(all(ans));
 cout<<ans.size()<<nl;
 for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}
int main() {
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
const int N=1e5+5;
vector<pair<int,int>>adj[N];vector<int>cost(N,-1);
void dijkstra(int start)
{
    priority_queue<pair<int,int>,deque<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    while(pq.size())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int node=p.second,nodecost=p.first;
        if(cost[node]!=-1)
        {
            continue;
        }
        cost[node]=nodecost;
        for(auto [node2,cost2]:adj[node])
        {
            if(cost[node2]==-1)
            {
                pq.push({nodecost+cost2,node2});
            }
        }
    }
}