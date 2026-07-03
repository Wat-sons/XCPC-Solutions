#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

ll dp[N][2];
vector<ll>e[N];


ll fac[N];
ll inv[N];
ll pre[N];

ll qpow(ll a,ll b,ll p)
{
    ll res = 1;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            res = res*a%p;
        }
        a = a*a%p;
    }
    return res;
}

ll C(ll n,ll m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}


void dfs(int u,int fa)
{
    if(u!=1&&e[u].size()==1)
    {
        dp[u][0]=1;
        return ;
    }
    
    ll res = 1;
    int cnt = 0 ;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        
        if(dp[v][0]!=-1)
        {
            res = res*dp[v][0]%mod;
            cnt++;
        }
        else
        {
            res = res*dp[v][1]%mod;
   
        }

    }
    res = res*pre[cnt]%mod*inv[cnt/2]%mod;
    if(cnt%2==1)dp[u][1] = res;
    else dp[u][0] = res;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=-1;
    
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1,0);



    cout<<dp[1][0]<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fac[0]=inv[0]=1;
    for(ll i=1;i<=N-10;i++)
    {
        fac[i] = fac[i-1]*i%mod;
        
    }

    inv[N-10] = qpow(fac[N-10],mod-2,mod);
    for(int i=N-11;i>=1;i--)
    {
        inv[i] = inv[i+1]*(i+1)%mod; 
    }
    
    for(int i=0;i<=N-10;i++)
    {
        if(i<3)pre[i]=1;
        else pre[i] = pre[i-2]*C(i,2)%mod;
    }




    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
