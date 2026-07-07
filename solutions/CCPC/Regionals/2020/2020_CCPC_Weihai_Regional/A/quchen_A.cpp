#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;

void solve()
{
    ull n,x,t;
    cin>>n>>x>>t;
    ull res = min(max(2*n*t+t,x+t)+2*n*t,max(2*n*t,2*t+x)+2*n*t);
    cout<<res<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
