#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll a[N];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll cur = 1;
    ll pre = 0;
    ll ans = 0;
    for(int i=1;i<=15;i++)
    {   
        ll sum = pre;
        for(int j=1;j<=n;j++)
        {
            sum+=(a[j]/cur)%10;
        }
        ans+=sum/10;
        pre = sum/10;
        cur = cur*10;
    }
    cout<<ans<<'\n';

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
