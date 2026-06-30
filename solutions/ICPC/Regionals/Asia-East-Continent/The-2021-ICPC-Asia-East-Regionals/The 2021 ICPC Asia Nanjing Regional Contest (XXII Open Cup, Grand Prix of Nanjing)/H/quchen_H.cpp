#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e17;
int n;
ll a[N],b[N];
vector<int>e[N];
ll dp[N],sum[N];
void dfs(int u,int fa)
{
    dp[u]=sum[u]=0;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        sum[u]+=dp[v];
    }

    pair<ll,int>mx1={-INF,0},mx2={-INF,0};
    for(auto v:e[u])
    {
        
        if(v==fa)continue;
        dp[u] = max(dp[u],sum[u]+a[v]);

        ll res= sum[v]+a[v]-dp[v];
        if(res>mx1.first)
        {
            mx2 = mx1;
            mx1.first = res;
            mx1.second = v;
            
        }
        else if(res>mx2.first)
        {
            mx2.first = res;
            mx2.second = v;
        }
        
        

    }

    for(auto v:e[u])
    {
        if(v==fa)continue;
        if(b[v]!=3)continue;
        ll res = (mx1.second!=v?mx1.first:mx2.first)+sum[u]+a[v];
        dp[u] = max(dp[u],res);
        
    }
}

void solve()
{   
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        e[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);

    cout<<dp[1]+a[1]<<'\n';

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
