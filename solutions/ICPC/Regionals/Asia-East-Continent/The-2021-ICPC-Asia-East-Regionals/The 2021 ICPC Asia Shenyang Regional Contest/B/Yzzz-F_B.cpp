#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e5+5;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>e(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    int ans=0;
    bool ok=1;
    for(int pos=0;pos<30;pos++){
        vector<bool>vis(n+1,0);
        vector<int>col(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cnt0=0,cnt1=0;
                auto dfs=[&](auto &&self,int u,int c)->void{
                    if(!ok) return;
                    vis[u]=1;
                    col[u]=c;
                    if(c)cnt1++;
                    else cnt0++;
                    for(auto [v,w]:e[u]){
                        int bit=(w>>pos)&1;
                        int nc=c^bit;
                        if(!vis[v]){
                            self(self,v,nc);
                        }else{
                            if(col[v]!=nc){
                                ok=false;   
                                return;
                            }
                        }
                    }
                };
                dfs(dfs,i,0);
                if(!ok) break;
                ans+=min(cnt0,cnt1)*(1LL<<pos);
            }
        }
        if(!ok) break;
    }
    if(ok)cout<<ans<<'\n';
    else cout<<-1<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
