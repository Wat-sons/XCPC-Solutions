#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll a,b,c;

void solve()
{
    cin>>a>>b>>c;

    ll res = INF;

    ll cur = 1;
    for(int i=0;i<=34;i++)
    {
        ll ta = i*a;
        ll ttb = (c+cur-1)/cur;
        ll tb = ttb*b;
        ll ans = ta+tb;
        res = min(res,ans);
        cur = cur*2;
    }
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
