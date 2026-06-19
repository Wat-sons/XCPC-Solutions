#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll n,k;
ll a[N],b[N];
ll c[N];

void solve()
{
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>b[i];
    }
    sort(a,a+k);
    sort(b,b+k);
    ll ans = INF;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            c[j] = (b[(j+i)%k]-a[j]+n)%n;
        }

        sort(c,c+k);
        ll cur0 = min(c[k-1],n-c[0]);
        ans = min(ans,cur0);

        for(int j=1;j<k;j++)
        {
            ll cur = min(n-c[j],c[j-1])+c[j-1]+n-c[j];
            ans = min(ans,cur);
        }

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
