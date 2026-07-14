#include <bits/stdc++.h>
using namespace std;
const int N= 1e3+10;
const int M = 1e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 2e18;;
ll n,m,st,ed;
int h[N],e[M*2],ne[M*2],idx;
ll f[M*2];
int d[N],cur[N];// d是分层图的层数，cur是当前弧优化
ll k1,k2;
char b[251][251];

void add(int a,int b,ll c)
{
    e[idx] = b;f[idx]=c,ne[idx]=h[a];h[a]=idx++;
    e[idx] = a;f[idx]=0;ne[idx]=h[b];h[b]=idx++;
}

bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>q;
    q.push(st);
    d[st] = 0;
    cur[st] = h[st];
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=h[u];i!=-1;i=ne[i])
        {
            int v = e[i];
            if(d[v]==-1&&f[i]>0)
            {
                d[v] = d[u]+1;
                cur[v] = h[v];
                if(v==ed)return true;
                q.push(v);
            }
        }
    } 

    return false;
}

ll find(int u,ll limit)
{
    if(u==ed)return limit;
    ll flow = 0;
    for(int i=cur[u];i!=-1&&flow<limit;i=ne[i])
    {
        cur[u] = i;// 当前弧优化
        int v = e[i];
        if(d[v]==d[u]+1&&f[i]>0)
        {
            ll tmp = find(v,min(f[i],limit-flow));
            if(!tmp)d[v] = -1; //剪枝：如果从v出发找不到增广路，标记v
            f[i] -= tmp;
            f[i^1] += tmp;
            flow += tmp;
        }
    }
    return flow;
}

ll dinic()
{
    ll max_flow = 0,flow;
    while(bfs())
    {
        while((flow=find(st,INF)))max_flow += flow;
    }
    return max_flow;

}

ll calc(ll x)
{
    memset(h,-1,sizeof(h));
    idx = 0;
    st = 0 ;
    ed = n+m+1;

    for(int i=1;i<=n;i++)
    {
        add(st,i,x);
    }
    for(int i=1;i<=m;i++)
    {
        add(n+i,ed,x);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]=='.')
            {
                add(i,n+j,1);
            }
        }
    }

    return dinic();
}

void solve()
{
    cin>>n>>m>>k1>>k2;
    ll tot = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>b[i][j];
            if(b[i][j]=='.')tot++;
        }
    }

    ll ans = INF;
    for(ll i=0;i<=max(n,m);i++)
    {
        ll c = calc(i);
        ll z = tot-c;
        ans = min(ans,k1*i+k2*z);
    }
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
