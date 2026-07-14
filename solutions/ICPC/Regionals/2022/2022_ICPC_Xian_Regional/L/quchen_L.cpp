#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll res = 0;
ll dep[N];
ll dp[N];
vector<int>e[N];

void dfs(ll u)
{
    dep[u]=1;
    for(auto v:e[u])
    {
        dfs(v);
        dep[u] = max(dep[v]+1,dep[u]);
    }
    dp[dep[u]]++;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
        dp[i]=0;
    }
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        e[x].push_back(i);
    }
    dfs(1);
    ll ans = INF;
    for(int i=1;i<=n;i++)
    {
        ans = min(ans,dp[i]+i-1);
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
