#include <bits/stdc++.h>
#define ll long long
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

///////////////////////////////////////////////////////
void solve() {
  /*
 - order_of_key (k) : Number of items strictly smaller than k.
 - find_by_order(k) : K-th element in a set (counting from zero).
*/
/*
  
  less: less<T> means that the tree is ordered in ascending order.
  greater: greater<T> means that the tree is ordered in descending order.
  less_equal: less_equal<T> means that the tree is ordered in ascending order but the tree allows multiple keys.
  greater_equal: greater_equal<T> means that the tree is ordered in descending order but the tree allows multiple keys.

*/
  int a,b,c=0;cin >> a >> b;
  vec<int>v(a),x;
  Tree<pair<int,int>>s;
  for(int i = 0; i <a; i++)cin>>v[i];
  for(int i = 0; i <b; i++)s.insert({v[i],i});
  if(b&1)x.push_back((s.find_by_order(b/2)->first));
  else {x.push_back((s.find_by_order((b/2)-1)->first));}
  for(int i=b;i<a;i++){
    s.erase(s.find({v[c],c}));
    s.insert({v[i],i});c++;
    if(b&1)x.push_back((s.find_by_order(b/2)->first));
  else {x.push_back((s.find_by_order((b/2)-1)->first));}
  // cout<<s.size()<<" ";
  }
   for(int i=0;i<x.size();i++)cout<<x[i]<<" ";
}
int main() {
    Moageza
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}
