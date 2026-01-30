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
const int N = 2e5 + 5;
int n, q, a[N], T[N][22], Log[N];
int merge(int a, int b)
{
    return (a | b);
}

void build()
{
    for (int i = 1; i <= n; i++)
        T[i][0] = a[i];

    for (int pw = 1; (1 << pw) <= n; pw++)
    {
        for (int i = 1; i + (1 << pw) - 1 <= n; i++)
            T[i][pw] = merge(T[i][pw - 1], T[i + (1 << (pw - 1))][pw - 1]);
    }
}

int query(int l, int r)
{
    int sz = r - l + 1;
    int pw = Log[sz];
    return merge(T[l][pw], T[r - (1 << pw) + 1][pw]);
}

void preCount()
{
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i >> 1] + 1;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    preCount();
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build();
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<query(--l,--r)<<'\n';
    }
    return 0;
}