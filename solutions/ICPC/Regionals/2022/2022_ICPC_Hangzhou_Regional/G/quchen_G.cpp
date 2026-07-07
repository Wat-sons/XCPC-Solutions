#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;
vector<int>e[N];
int deg[N];
int vis[N];


ull h[N];

const ull mask = std::mt19937_64(time(nullptr))();

ull shift(ull x) 
{
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

void dfs(int u,int fa)
{
    h[u] = 1;
    for(auto v:e[u])
    {
        if(vis[v]==2||v==fa||!vis[v])continue;
        dfs(v,u);
        h[u] += shift(h[v]);
    }
}



void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
        deg[i]=0;
        vis[i]=0;
        h[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[v]++;
        deg[u]++;
    }


    if(m==n-1)
    {
        cout<<"YES\n";
        return ;
    }
    else if(n<m)
    {
        cout<<"NO\n";
        return ;
    }    
    

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)
        {
            q.push(i);
        }   
    }   


    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for(auto v:e[u])
        {
            if(--deg[v]==1)
            {
                q.push(v);
            }
        }
    }


    vector<int>p;
    int cur = -1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            cur = i;
            break;
        }
    }
    p.push_back(cur);
    while(1&&cur!=-1)
    {
        bool ok = false;
        vis[cur]=2;
        dfs(cur,0);
        for(auto v:e[cur])
        {
            if(vis[v]==0)
            {
                p.push_back(v);
                cur = v;
                ok = true;
                break;

            }
        }
        if(!ok)break;

    }


    int sz = p.size();
    if(sz%2==1)
    {
        for(int i=1;i<sz;i++)
        {
            if(h[p[i]]!=h[p[i-1]])
            {
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
    }
    else 
    {
        for(int i=2;i<sz;i++)
        {
            if(h[p[i]]!=h[p[i-2]])
            {
                cout<<"NO\n";
                return ;
            }
        }
        cout<<"YES\n";
    }


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
