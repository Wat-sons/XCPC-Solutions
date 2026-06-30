#include <bits/stdc++.h>
using namespace std;
const int N=4e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll dp[N][N][2];
ll p[N];

ll sz[N];
vector<int>e[N];

void dfs(int u,int fa)
{
    sz[u] = 1;
    dp[u][0][0]=1;
    for(auto v:e[u])
    {
        if(fa==v)continue;
        dfs(v,u);
        
        for(int i=sz[u]/2;i>=0;i--)
        {
            for(int j=sz[v]/2;j>=0;j--)
            {
                if(j>0)
                {
                    dp[u][i+j][0] = (dp[u][i+j][0]+dp[u][i][0]*(dp[v][j][1]+dp[v][j][0])%mod)%mod;
                    dp[u][i+j][1] = (dp[u][i+j][1]+dp[u][i][1]*(dp[v][j][1]+dp[v][j][0])%mod)%mod;
                }
                dp[u][i+j+1][1] = (dp[u][i+j+1][1]+dp[u][i][0]*dp[v][j][0]%mod)%mod;
            }
        }
        sz[u]+=sz[v];
    }

}


void solve()
{
    cin>>n;
    p[0]=1;
    for(int i=1;i<=n;i++)p[i] = p[i-1]*(2*i-1)%mod;
    for(int i=1;i<=2*n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);

    ll res = p[n];


    for(int i=1;i<=n;i++)
    {
        ll cur = dp[1][i][0]+dp[1][i][1];
        cur = cur*p[n-i]%mod;
        if(i%2==1)res = (res-cur+mod)%mod;
        else res = (res+cur)%mod;
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
