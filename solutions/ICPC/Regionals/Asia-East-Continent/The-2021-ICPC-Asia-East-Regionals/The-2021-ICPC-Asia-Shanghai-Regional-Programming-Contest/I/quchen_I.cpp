#include <bits/stdc++.h>
using namespace std;
const int N=3e2+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e15;
const ll dx = 1e4;
int n,k;
ll v[N],w[N];

void solve()
{
    cin>>n>>k;
    ll mx = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
        mx = max(mx,w[i]);
    }

    vector<vector<ll>>dp(mx*4*n+1,vector<ll>(k+2,-INF));
    ll dx = 2*n*mx;
    dp[dx+w[1]][0] = v[1];
    dp[dx-w[1]][0] = v[1];
    dp[dx+2*w[1]][1] = v[1];
    dp[dx-2*w[1]][1] = v[1];
    dp[dx][0]=0;
    for(int i=2;i<=n;i++)
    {
        vector<vector<ll>>ndp(mx*4*n+1,vector<ll>(k+1,-INF));
        for(int j=0;j<=mx*4*n;j++)
        {
            for(int t=0;t<=k;t++)
            {
                if(j>=w[i])ndp[j][t] = max(ndp[j][t],dp[j-w[i]][t]+v[i]);
                if(j+w[i]<=mx*4*n) ndp[j][t] = max(ndp[j][t],dp[j+w[i]][t]+v[i]);
                ndp[j][t] = max(ndp[j][t],dp[j][t]);
                if(t>=1&&j>=2*w[i])ndp[j][t] = max(ndp[j][t],dp[j-2*w[i]][t-1]+v[i]);
                if(t>=1&&j+2*w[i]<=mx*4*n)ndp[j][t] = max(ndp[j][t],dp[j+2*w[i]][t-1]+v[i]);


            }
            
        }
        dp = ndp;

    }

    ll ans = 0;
    for(int i=0;i<=k;i++)
    {
        ans = max(ans,dp[dx][i]);
    }

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
