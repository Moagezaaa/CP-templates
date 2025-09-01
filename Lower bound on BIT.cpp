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
struct BIT {
    vector<int> tree;
    int size;

    BIT(int n) : size(n), tree(n + 2) {}

    void update(int idx, int delta) {
        if(idx==0)return;
        for (; idx <= size; idx += idx & -idx)
            tree[idx] += delta;
    }

    int query(int idx) {
        if(idx==0)return 0;
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	
	for(int i=30; i>=0; i--)
	{
		if(pos + (1 << i) < size and sum + tree[pos + (1 << i)] < v)
		{
			sum += tree[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; 
}
};
void solve() {
    int a,b;cin >> a>>b;
    BIT p(a+5);
    for(int i=0;i<a;i++){
        int x;cin>>x;
        p.update(x,1);
    }
    while(b--){
        int x;cin>>x;
        if(x<0){x=abs(x);
           int y= p.bit_search(x);
           p.update(y,-1);
        }
        else{
            p.update(x,1);
        }
    }
    for(int i=1;i<=a;i++){
        if(p.tree[i])rv(cout<<i);
    }
    cout<<0;
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
