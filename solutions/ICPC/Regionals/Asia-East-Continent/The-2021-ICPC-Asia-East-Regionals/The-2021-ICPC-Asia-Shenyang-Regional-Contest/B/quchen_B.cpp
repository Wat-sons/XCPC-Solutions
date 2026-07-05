#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e9;
int n,m;

bool vis[N];
int b[N];

vector<pair<int,int>>e[N];
bool ok=true;
set<int>st;

void dfs2(int u)
{
    st.insert(u);
    vis[u] = true;
    for(auto [v,w]:e[u])
    {
        if(vis[v])continue;
        dfs2(v);        
    }
}
void dfs(int u,int idx)
{   
    if(!ok)return;

    for(auto [v,w]:e[u])
    {   
        int a = ((w>>idx)&1);
        if(b[v]!=-1)
        {
            if((b[v]^b[u])!=a)
            {
                ok = false;
                return ;
            }
            continue;
        }
        b[v] = b[u]^a;
        dfs(v,idx);
    }

}



void solve()
{   
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});

    }

    ll ans = 0;

    for(int i=1;i<=n;i++)
    {   
        if(vis[i])continue;
        st.clear();
        dfs2(i);
        for(int j=0;j<30;j++)
        {
            ll cans = INF;
            ok = true;
            for(auto v:st)b[v]=-1;
            b[i]=0;
            dfs(i,j);
            ll cnt = 0;
            if(ok)
            {
                for(auto u:st)cnt+=b[u];
                cans = min(cans,cnt);
                cnt=0;
            }
            ok = true;
            for(auto v:st)b[v]=-1;
            b[i] = 1;
            dfs(i,j);    
            if(ok)
            {
                for(auto u:st)cnt+=b[u];
                cans = min(cans,cnt);
                cnt = 0;
            }
            if(cans==INF)
            {
                cout<<-1<<'\n';
                return ;
            }
            ans += cans*(1<<j);

            
        }
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
