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
// const ll mod = 1e9+7,N=2e5+5;
//////////////////////////////////////////////////////
void solve(){
    int n; cin >> n;
    vec<int>a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> v; // stores the number of times a subarray (gcd,any thing) occurs ending at each index
  map<int, long long> ans;
set<int>s;
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int>> u;
    u.push_back({a[i], 1});
    for (auto [x, c]: v) {
      int g = gcd(x, a[i]);
      if (g == u.back().first) {
        u.back().second += c;
      } else {
        u.push_back({g, c});
      }
    }
    v = u;
    for (auto [x, c]: v) {
      ans[x] += c;
s.insert(x);// use to find the distinct numbers
    }
  }

  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    cout << ans[x] << '\n';
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