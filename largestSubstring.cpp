#include <bits/stdc++.h>
// #define int long long
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
string largestSubstring(string s) {
    int n = s.size();

    int i = 0, j = 1, k = 0;

    while (j + k < n) {
        if (s[i + k] == s[j + k]) {
            k++;
        }
        else if (s[i + k] < s[j + k]) {
            i = max(i + k + 1, j);
            j = i + 1;
            k = 0;
        }
        else {
            j = j + k + 1;
            k = 0;
        }
    }

    return s.substr(i);
}
void solve(){
 str a;cin>>a;
    cout<<largestSubstring(a);
}

signed main() {
    Moageza
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}