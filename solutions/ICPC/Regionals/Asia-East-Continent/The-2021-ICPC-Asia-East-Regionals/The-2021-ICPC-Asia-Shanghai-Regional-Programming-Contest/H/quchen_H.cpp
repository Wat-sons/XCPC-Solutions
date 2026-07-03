#include <bits/stdc++.h>
using namespace std;
const int N=4e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m,q;


struct Edge
{
    int u,v;
    ll w;
}e[N];

int fa[N];

ll st[25][N];
ll est[25][N];
int tot = 0;
ll cost[N],a[N];



bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}


int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void solve()
{
    cin>>n>>m>>q;
    tot = n;
    
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }

    sort(e+1,e+1+m,cmp);

    for(int i=1;i<=m;i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        ll w = e[i].w;
        int fu = find(u);
        int fv = find(v);
        if(fu==fv)continue;
        tot++;
        a[tot] = a[fu]+a[fv];
        cost[tot]=w;

        est[0][fu] = est[0][fv] = tot;
        st[0][fu] = w-a[fu];
        st[0][fv] = w-a[fv];

        fa[fu] = tot;
        fa[fv] = tot;
        fa[tot] = tot;
    }


    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=tot;j++)
        {
            int x = est[i-1][j];
            if(x)
            {
                est[i][j] = est[i-1][x];
                st[i][j] = max(st[i-1][j],st[i-1][x]);
            }
        }
    }

    while(q--)
    {
        int x,k ;
        cin>>x>>k;

        for(int i=20;i>=0;i--)
        {
            if(est[i][x]&&st[i][x]<=k)
            {
                x = est[i][x];
            }
        }
        ll res = a[x]+k;
        cout<<res<<'\n';
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
