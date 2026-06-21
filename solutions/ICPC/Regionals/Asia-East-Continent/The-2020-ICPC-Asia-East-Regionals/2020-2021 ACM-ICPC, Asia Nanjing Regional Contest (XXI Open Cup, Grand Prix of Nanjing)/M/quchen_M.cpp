#include <bits/stdc++.h>
using namespace std;
const int N=4e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

vector<int>e[N];
ll hp[N];
int p[N];
ll dp[N][N][2];
ll ans = 0;
ll sz[N];
ll ndp[N][2];
ll tmp[N][2];
ll sum[N];

void dfs(int u)
{   
    if(u!=0)sz[u]=1;
    for(auto v:e[u])
    {
        dfs(v);
        memset(tmp,0,sizeof(tmp));
        memset(ndp,0,sizeof(ndp));

        for(int i=0;i<=sz[v];i++)
        {
            tmp[i][0] = max(tmp[i][0],dp[v][i][0]);
            tmp[i][1] = max(tmp[i][1],dp[v][i][0]);

            tmp[i+1][0] = max(tmp[i+1][0],dp[v][i][1]+sum[v]+((v>1)?hp[v]:0LL));
            tmp[i+1][1] = max(tmp[i+1][1],dp[v][i][1]+sum[v]);
        }


        for(int i=0;i<=sz[v];i++)
        {
            for(int j=0;j<=sz[u];j++)
            {
                ndp[i+j][0] = max(ndp[i+j][0],dp[u][j][0]+tmp[i][0]);
                ndp[i+j][1] = max(ndp[i+j][1],dp[u][j][1]+tmp[i][1]);

            }
        }
        sz[u]+=sz[v];

        for(int j=0;j<=sz[u];j++)
        {
            dp[u][j][0] = ndp[j][0];
            dp[u][j][1] = ndp[j][1];
        }
    }
}


void solve()
{
    cin>>n;
    ans=0;
    for(int i=0;i<=n;i++)
    {
        e[i].clear();
        p[i]=-1;
        sum[i]=0;
        
    }

    e[0].push_back(1);
    
    for(int i=2;i<=n;i++)
    {
        int u;
        cin>>u;
        e[u].push_back(i);
        p[i]=u;

    }

    for(int i=1;i<=n;i++)
    {
        cin>>hp[i];
        if(i>1)ans+=hp[i];
        ans+=hp[i];
        sum[i] = hp[i];
        
    }
    for(int i=2;i<=n;i++)
    {
        sum[p[i]]+=hp[i];
    }

    for(int i=0;i<=n;i++)
    {
        memset(dp[i],0,sizeof(dp[i]));
    }

    dfs(0);

    for(int i=0;i<=n;i++)
    {
        cout<<ans-max(dp[0][i][0],dp[0][i][1])<<' ';
    }
    cout<<'\n';
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
