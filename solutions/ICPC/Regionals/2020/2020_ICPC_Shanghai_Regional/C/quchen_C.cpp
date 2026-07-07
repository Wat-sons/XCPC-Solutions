#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

ll x,y;

ll dp[40][2][2][2];

int a[50],b[50];

ll dfs(ll pos,bool lim1,bool lim2,int sum)
{
    if(pos==0)
    {
        if(sum)return 0;
        else return 1;
    }

    if(dp[pos][lim1][lim2][sum]!=-1)return dp[pos][lim1][lim2][sum];

    int mx1 = lim1?a[pos]:1;
    int mx2 = lim2?b[pos]:1;

    ll res = 0;
    for(int i=0;i<=mx1;i++)
    {
        for(int j=0;j<=mx2;j++)
        {
            if(i==1&&j==1)continue;

            ll w;
            if(sum&&(i||j))w = pos;
            else w = 1;
            
            res = (res+dfs(pos-1,lim1&&(a[pos]==i),lim2&&(b[pos]==j),sum&&(!i)&&(!j))*w%mod)%mod;

        }

    }
    dp[pos][lim1][lim2][sum] = res;
    return res;
}

void solve()
{
    memset(dp,-1,sizeof(dp));

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    cin>>x>>y;

    ll res = 0;

    if(!x&&!y)
    {
        cout<<0<<'\n';
        return ;
    }

    int idx = 0;
    while(x||y)
    {
        a[++idx] = x%2;
        b[idx] = y%2;
        x/=2;
        y/=2;

    }
    ll ans = dfs(idx,1,1,1);
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
