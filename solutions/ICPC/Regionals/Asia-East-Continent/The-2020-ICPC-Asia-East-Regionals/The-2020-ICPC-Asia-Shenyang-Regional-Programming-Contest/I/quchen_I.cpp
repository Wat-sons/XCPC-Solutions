#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;

ll h,m,A;

void solve()
{
    cin>>h>>m>>A;
    ll ans = 0;
    ll g = gcd(h-1,h*m);

    ll ans1 = A/g+1;
    ll ans2 = A/g;

    ll T = h*m;
    if(2*A>=T)
    {
        if(A%g==0)ans--;
    }

    ans+=ans1;
    ans+=ans2;
    ans = ans*g;
    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
