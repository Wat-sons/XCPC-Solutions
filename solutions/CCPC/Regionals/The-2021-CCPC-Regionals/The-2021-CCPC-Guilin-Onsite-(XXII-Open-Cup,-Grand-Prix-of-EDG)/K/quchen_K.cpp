#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;
vector<pair<ll,int>>e[N];
ll w[N];

ll dis[N];
bool vis[N];
ll cnt[N];
ll res[N];


void bfs()
{

    for(int i=1;i<=n;i++)dis[i]=-1;
    dis[1]=0;
    queue<int>q;
    q.push(1);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x:e[u])
        {
            int v = x.first;
            if(dis[v]==-1)
            {
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }

}

void dfs(int u,ll cur)
{
    
    res[u] = min(res[u],cur);


    for(auto x:e[u])
    {
        int v = x.first;
        int c = x.second;
        if(dis[v]!=dis[u]+1)continue;
        cnt[c]++;
        dfs(v,cnt[c]*w[c]+cur);
        cnt[c]--;
    }

    
}


void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        res[i] = INF;
    }
    res[1] = 0;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        cnt[i]=0;
    }

    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        e[u].push_back({v,c});
        e[v].push_back({u,c});

    }

    bfs();

    dfs(1,0);
    
    


    for(int i=2;i<=n;i++)
    {
        cout<<res[i]<<'\n';
    }




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
