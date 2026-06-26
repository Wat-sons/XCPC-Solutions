#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e15;
int n,m;
ll k;
vector<pair<int,ll>>e[N];
bool vis[N];
ll dis[N];
void dj(int x)
{   
    
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dis[i] = INF;
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    for(auto [v,w]:e[x])
    {
        pq.push({w,v});
        dis[v]=w;
    }

    while(!pq.empty())
    {
        auto xx = pq.top();
        pq.pop();
        int u = xx.second;
        if(vis[u])continue;
        vis[u]=true;
        for(auto [v,w]:e[u])
        {
            if(!vis[v]&&dis[v]>=dis[u]+w)
            {
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }   
        }
    }

    


}

void solve()
{
    cin>>n>>m>>k;
    ll mn = INF;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});

        mn = min(mn,w);


    }

    if(mn>k)
    {
        cout<<0<<'\n';
        return ;
    }

    for(int i=1;i<=n;i++)
    {   
        dj(i);
        // for(int j=1;j<=n;j++)
        // {
        //     cout<<dis[j]<<' ';
        // }
        // cout<<'\n';
        if(dis[i]<=k)
        {
            cout<<2<<'\n';
            return ;
        }

    }
    cout<<1<<'\n';


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
