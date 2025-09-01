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
class LCA {
public:
    LCA(
        int n = 0,
        const vector < vector < int > > &G = {},
        int root = 1
    ) : N(n), LOG(0), ROOT(root), adj(G) {
        while((1 << LOG) <= N) LOG++;
        anc.assign(N + 5, vector < int > (LOG));
        depth.assign(N + 5, 0);
        dfs(ROOT);
    }

    int kth_ancestor(int u, int k) const {
        if(depth[u] < k) return -1;
        for(int bit = 0; bit < LOG; bit++)
            if(k & (1 << bit)) 
                u = anc[u][bit];
        return u;
    }

    int get_lca(int u, int v) const {
        if(depth[u] < depth[v]) swap(u, v);

        u = kth_ancestor(u, depth[u] - depth[v]);
        if(u == v) return u;
        
        for(int bit = LOG - 1; bit >= 0; bit--)
            if(anc[u][bit] != anc[v][bit])
                u = anc[u][bit], v = anc[v][bit];
        
        return anc[u][0];
    }

    int get_dist(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
    }

private:
    int N, LOG, ROOT;
    const vector < vector < int > > &adj;
    vector < vector < int > > anc;
    vector < int > depth;

    void dfs(int u, int p = 0){
        for(int v : adj[u]){
            if(v == p) continue;
            depth[v] = depth[u] + 1;
            anc[v][0] = u;
            for(int bit = 1; bit < LOG; bit++){
                anc[v][bit] = anc[anc[v][bit - 1]][bit - 1];
            }
            dfs(v, u);
        }
    }
};

void solve() {
    int a,b;cin >> a>>b;
    vector<vector<int>> adj(a+1);
    for (int i = 2; i <= a; i++) {
        int x,y;
        cin >> x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    LCA lca(a, adj, 1);
    while (b--) {
        int u, v;
        cin >> u >> v;
        cout << lca.get_dist(u, v) << nl;
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