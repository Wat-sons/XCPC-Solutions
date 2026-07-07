#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e15;
ll n,m;

ll w[N][11];
ll p[N];


void solve()
{
    ll sum = 0;
    ll res = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        for(int j=1;j<=p[i];j++)
        {
            cin>>w[i][j];
        }
        res+=w[i][p[i]];
        sum+=p[i];
    }

    if(sum<=m)
    {
        cout<<res<<'\n';
        return ;
    }

    vector<vector<ll>>dp(m+1,vector<ll>(2,-INF));
    vector<vector<ll>>ndp(m+1,vector<ll>(2,-INF));
    dp[0][0]=dp[0][1]=0;

    for(int i=1;i<=n;i++)
    {
        ndp = dp;
        for(int j=m;j>=0;j--)
        {
            
            if(j>=p[i])
            {
                ndp[j][0] = max(ndp[j][0],dp[j-p[i]][0]+w[i][p[i]]);
                ndp[j][1] = max(ndp[j][1],dp[j-p[i]][1]+w[i][p[i]]);
            }
            for(int k=1;k<=p[i];k++)
            {
                if(j>=k)
                {
                    ndp[j][1] = max(ndp[j][1],dp[j-k][0]+w[i][k]);
                }
            }
           
        }
        dp = ndp;
    }

    cout<<max(dp[m][0],dp[m][1])<<'\n';


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
