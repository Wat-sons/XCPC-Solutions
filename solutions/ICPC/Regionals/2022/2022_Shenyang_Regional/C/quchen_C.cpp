#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,d;
ll a[N];


void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    ll res = 0;

    for(int i=1;i<=n;i++)
    {

        ll l = a[i];
        ll r = a[i]+d;
        ll ans = 0;
        for(int j=2;j<=n;j++)
        {
            ll x = a[j];
            ll y = a[j-1];
            if(x<l)x=l;
            else if(x>r)x=r;
            if(y<l)y = l;
            else if(y>r)y=r;
            ans+=abs(x-y);
        }
        res = max(res,ans);

    }


    for(int i=1;i<=n;i++)
    {

        ll r = a[i];
        ll l = a[i]-d;
        ll ans = 0;
        for(int j=2;j<=n;j++)
        {
            ll x = a[j];
            ll y = a[j-1];
            if(x<l)x=l;
            else if(x>r)x=r;
            if(y<l)y = l;
            else if(y>r)y=r;
            ans+=abs(x-y);
        }
        res = max(res,ans);

    }

    cout<<res<<'\n';

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
