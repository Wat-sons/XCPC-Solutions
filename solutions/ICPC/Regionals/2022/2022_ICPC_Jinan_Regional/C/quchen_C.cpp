#include <bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll dp[505][505];
vector<int>e[N];
ll fac[N],tot[N],sz[N];


ll qpow(ll a,ll b,ll p)
{
    ll res=1;
    for(;b;b>>=1)
    {
        if(b&1)res =res*a%p;
        a = a*a%p;
    }
    return res;
}


ll dfs(int u,int fa)
{   
    sz[u]=1;
    tot[u]=0;
    ll res = 1;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        res = res*dfs(v,u)%mod;
        sz[u]+=sz[v];
        tot[u]++;
        
    }

    res = res*fac[tot[u]]%mod;

    return res;

}


void dfs2(int u,int fa)
{

    vector<vector<ll>>f(n+1,vector<ll>(n+1,0));
    f[0][0]=1;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        for(int i=tot[u];i>=1;i--)
        {
            for(int j=sz[u];j>=sz[v];j--)
            {
                f[i][j] = (f[i][j]+f[i-1][j-sz[v]])%mod;
            }
        }

    }



    for(auto v:e[u])
    {
        if(v==fa)continue;
        for(int i=1;i<=tot[u];i++)
        {
            for(int j=sz[v];j<=sz[u];j++)
            {
                f[i][j] = (f[i][j]-f[i-1][j-sz[v]]+mod)%mod;
            }
        }

        vector<ll>g(n+2,0);
        for(int i=0;i<=tot[u]-1;i++)
        {
            for(int j=0;j<=sz[u];j++)
            {
                g[j+1] = (g[j+1]+fac[i]*fac[tot[u]-i-1]%mod*f[i][j]%mod)%mod;
            }
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+j<=n)
                {
                    dp[v][i+j] = (dp[v][i+j]+dp[u][i]*g[j]%mod)%mod;
                }
            }
        }


        for(int i=tot[u];i>=1;i--)
        {
            for(int j=sz[u];j>=sz[v];j--)
            {
                f[i][j] = (f[i][j]+f[i-1][j-sz[v]])%mod;
            }
        }

    

    }


    for(auto v:e[u])
    {
        if(v==fa)continue;
        dfs2(v,u);
    }



}



void solve()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    dp[1][1]=dfs(1,0);
    dfs2(1,0);

    for(int i=1;i<=n;i++)
    {
        ll sum = 0;
        for(int j=1;j<=n;j++)
        {
            sum = (sum+dp[i][j])%mod;
        }

        ll inv = qpow(sum,mod-2,mod);
        for(int j=1;j<=n;j++)
        {
            ll res = dp[1][1]*dp[i][j]%mod*inv%mod;    
            cout<<res<<' ';
        }
        cout<<'\n';
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    fac[0]=1;
    for(int i=1;i<=500;i++)
    {
        fac[i] = fac[i-1]*i%mod;
    }
    // cin>>t;

    while(t--)
    {
        solve();

    }


    return 0;
}
