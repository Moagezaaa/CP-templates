#include <bits/stdc++.h>
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
//////////////////////////////////////////////////////
struct BIT {
    vector<int> tree;
    int size;
 
    BIT(int n) : size(n), tree(n + 2, 0) {}
 
    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx)
            tree[idx] += delta;
    }
 
    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }
    
    int range_query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vec<int> a(n), b(n);
    vec<vec<int>> pos(n + 1);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vec<BIT> zeros(21, BIT(n)), ones(21, BIT(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (a[i] & (1 << j)) {
                ones[j].update(i + 1, 1);
            } else {
                zeros[j].update(i + 1, 1);
            }
        }
    }
    
    int ans = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int idx = pos[b[i]].back();
        pos[b[i]].pop_back();
        int bit_idx = idx + 1;
        
        for (int j = 0; j <= 20; j++) {
            if (b[i] & (1 << j)) {
                int cnt = zeros[j].range_query(bit_idx + 1, n);
                ans += cnt * (1LL << j);
            } else {
                int cnt = ones[j].range_query(bit_idx + 1, n);
                ans += cnt * (1LL << j);
            }
          }
        for (int j = 0; j <= 20; j++) {
            if (a[idx] & (1 << j)) {
                ones[j].update(bit_idx, -1);
            } else {
                zeros[j].update(bit_idx, -1);
            }
        }
    }
    
    cout << ans ;
}

signed main() {
    Moageza
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}