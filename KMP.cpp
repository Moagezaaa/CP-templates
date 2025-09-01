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
// check the number of all prfiex occurs in the string 
//  vec<int>l(n+1,0);
//  for(int i=0;i<n;i++)l[longestPrefix[i]]++;
//  for(int i=n-1;i>0;i--)l[longestPrefix[i-1]]+=l[i];
//  for(int i=0;i<=n;i++)l[i]++;
    // for(int i=0;i<n;i++)cout<<longestPrefix[i]<<" ";
    // cout<<nl;
    // for(int i=1;i<=n;i++)cout<<l[i]<<" ";
    // for (int k = 1; k <= n; ++k) {
    //     string prefix = a.substr(0, k);
    //     string suffix = a.substr(n - k, k);
    //     if (prefix == suffix) {
    //        cout<< l[k];
    //     }
    // }
vector<int>ans,longestPrefix;
struct KMP{
    void calcPrefix(string patern)
    {
        longestPrefix.assign(patern.size(),0);
        int n=patern.size();
        for(int i=1,idx=0;i<n;i++)
        {
            while(idx>0&&patern[idx]!=patern[i])idx=longestPrefix[idx-1];
            if(patern[i]==patern[idx])idx++;
            longestPrefix[i]=idx;
        }
    }
    void kmp(string s,string pat)
    {
        int n=s.size(),m=pat.size();
        calcPrefix(pat);
        for(int i=0,idx=0;i<n;i++)
        {
            while(idx>0&&s[i]!=pat[idx])idx=longestPrefix[idx-1];
            if(s[i]==pat[idx])idx++;
            if(idx==m)ans.push_back(i-m+1),idx=longestPrefix[idx-1];
        }
    }
};
void solve(){
 str a;cin>>a;
    KMP kmp;
    int n=a.size();
    kmp.calcPrefix(a);
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