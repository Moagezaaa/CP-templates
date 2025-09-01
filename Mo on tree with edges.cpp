#include <bits/stdc++.h>
using namespace std;
#define ll int

struct coordinateCompression {
private:
    vector<ll> init;
    void compress(vector<ll>& v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
public:
    coordinateCompression(vector<ll>& v) {
        init = v;
        compress(init);
    }
    int index(ll val) {
        return lower_bound(init.begin(), init.end(), val) - init.begin();
    }
    ll initVal(int idx) {
        return init[idx];
    }
    int size() {
        return init.size();
    }
};

template < typename T = int, typename graphType = pair<int, int>, bool VAL_ON_EDGE = true >
class MoTree {
public:
    struct Query {
        int l, r, lca, queryIdx;
        long long ord;
        Query(vector<int>& S, vector<int>& E, int u = 0, int v = 0, int i = 0, int LCA = 0, int p = 0) {
            if (S[u] > S[v]) swap(u, v);
            if (LCA == u) {
                l = S[u] + VAL_ON_EDGE;
                r = S[v];
                lca = -1;
            } else {
                l = E[u];
                r = S[v];
                lca = LCA;
            }
            queryIdx = i;
            ord = hilbertOrder(l, r, p, 0);
        }
        static long long hilbertOrder(int x, int y, int pow, int rot) {
            if (!pow) return 0;
            int h = 1 << (pow - 1);
            int seg = (x < h) ? ((y < h) ? 0 : 3) : ((y < h) ? 1 : 2);
            seg = (seg + rot) & 3;
            static int rD[4] = { 3, 0, 0, 1 };
            int nx = x & (x ^ h), ny = y & (y ^ h);
            int nrot = (rot + rD[seg]) & 3;
            long long sub = 1LL << (2 * pow - 2);
            long long ord = seg * sub;
            long long add = hilbertOrder(nx, ny, pow - 1, nrot);
            ord += (seg == 1 || seg == 2) ? add : (sub - add - 1);
            return ord;
        }
        bool operator<(const Query& rhs) const {
            return ord < rhs.ord;
        }
    };

    MoTree(int n, int q, const vector<vector<graphType>>& g,
        const vector<T>& values = {}, int root = 1)
        : n(n), m(q), adj(g)
    {
        LOG = 1; while ((1 << LOG) <= n) LOG++;
        helPow = 0; while ((1 << helPow) < 2 * n) helPow++;

        S.assign(n + 5, 0);
        E = S;
        dep = S;
        FT.assign(2 * n + 5, 0);
        nodeFreq.assign(n + 5, 0);
        anc.assign(n + 5, vector<int>(LOG, 0));
        val = values;
        answers.assign(q, 0);

        timer = 1;
        dfs(root, adj);
        currL = 1, currR = 0;
        mex = 0;
    }

    void addQuery(int u, int v, int idx) {
        int LCA = getLCA(u, v);
        queries.emplace_back(S, E, u, v, idx, LCA, helPow);
    }

    void process() {
        sort(queries.begin(), queries.end());
        currL = queries[0].l;
        currR = queries[0].l - 1;

        for (auto& q : queries) {
            setRange(q);
            if (q.lca != -1 && !VAL_ON_EDGE)
                addOp(q.lca);
            answers[q.queryIdx] = mex;
            if (q.lca != -1 && !VAL_ON_EDGE)
                removeOp(q.lca);
        }
    }

    vector<T> getAnswers() { return answers; }

private:
    int n, m, LOG, helPow, timer, currL, currR;
    vector<vector<graphType>> adj;
    vector<int> S, E, dep, FT, nodeFreq;
    vector<vector<int>> anc;
    vector<T> val, answers;
    vector<Query> queries;

    static constexpr int MAXV = 21e5 + 5;
    vector<int> freq = vector<int>(MAXV, 0);
    T mex;

    void dfs(int u, const vector<vector<pair<int, int>>>& g, int p = -1) {
        S[u] = timer;
        FT[timer++] = u;
        for (auto& [v, w] : g[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            anc[v][0] = u;
            val[v] = w;
            for (int b = 1; b < LOG; b++)
                anc[v][b] = anc[anc[v][b - 1]][b - 1];
            dfs(v, g, u);
        }
        E[u] = timer;
        FT[timer++] = u;
    }

    int getLCA(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[u] - dep[v];
        for (int b = LOG - 1; b >= 0; b--)
            if (d & (1 << b)) u = anc[u][b];
        if (u == v) return u;
        for (int b = LOG - 1; b >= 0; b--)
            if (anc[u][b] != anc[v][b])
                u = anc[u][b], v = anc[v][b];
        return anc[u][0];
    }

    void setRange(const Query& q) {
        while (currL > q.l) op(--currL);
        while (currR < q.r) op(++currR);
        while (currL < q.l) op(currL++);
        while (currR > q.r) op(currR--);
    }

    void addNode(int u) {
        int x = val[u];
        if (x >= MAXV) return;
        freq[x]++;
        if (x == mex) while (freq[mex]) ++mex;
    }

    void remNode(int u) {
        int x = val[u];
        if (x >= MAXV) return;
        freq[x]--;
        if (x < mex && freq[x] == 0)
            mex = x;
    }

    void addOp(int u) { addNode(u); }
    void removeOp(int u) { remNode(u); }

    void op(int idx) {
        int u = FT[idx];
        nodeFreq[u] ^= 1;
        if (nodeFreq[u]) addOp(u);
        else removeOp(u);
    }
};

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> l;
    for (int i = 1; i < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        l.push_back(x);
        adj[u].push_back({ v, x });
        adj[v].push_back({ u, x });
    }
    coordinateCompression cc(l);
    vector<int> dummy(n + 1);
    vector<int> compressedVal(n + 1);
    for (int u = 1; u <= n; u++) {
        for (auto& [v, x] : adj[u]) {
            if (v > u) {
                compressedVal[v] = cc.index(x);
            }
        }
    }
    MoTree<int, pair<int, int>, true> mo(n, q, adj, compressedVal, 1);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        mo.addQuery(u, v, i);
    }

    mo.process();
    for (auto x : mo.getAnswers()) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
    Solve();
}