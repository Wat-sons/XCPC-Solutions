#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;

vector<pair<int,int>>e[N];
struct Edge
{
    int u,v;
    ll w;
}edge[N];
int cnte =1 ;
int cnt = 0;
bool cEdge[N];
int low[N],dfn[N];
stack<int>stk;
int sub[N];
ll mn=INF;

void tarjan(int u,int pre)
{
    dfn[u]=low[u] = ++cnt;

    stk.push(u);
    for(auto xx:e[u])
    {
        int v = xx.first;
        int id = xx.second;
        if((id^1)==pre)continue;
        if(dfn[v]==0)
        {
            tarjan(v,id);
            low[u]= min(low[u],low[v]);

            sub[u] += sub[v]+1;
            if(low[v]>dfn[u])
            {
                cEdge[id>>1] = true;
                if(sub[v]%2==0)mn = min(mn,edge[id>>1].w);
            }
            
        }
        else 
        {
            low[u] = min(low[u],dfn[v]);
            if(dfn[v]<dfn[u])sub[u]++;
        
        }
    }
}

void solve()
{
    cin>>n>>m;
    ll sum = 0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
        e[u].push_back({v,++cnte});
        e[v].push_back({u,++cnte});
        sum+=w;
    }


    if(m%2==0)
    {
        cout<<sum<<'\n';
        return ;
    }

    tarjan(1,0);

    ll ans = sum;
    for(int i=1;i<=m;i++)
    {
        if(!cEdge[i])mn = min(mn,edge[i].w);
    }
    ans -= mn;
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
