#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

using ull=unsigned long long;
ull mask;

ull shift(ull x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>e(n+1);
    vector<int>deg(n+1,0);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(m>n){
        cout<<"NO\n";
        return;
    }else if(m==n-1){
        cout<<"YES\n";
        return;
    }else{
        queue<int>q;
        vector<bool>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(deg[i]==1){
                q.push(i);
                vis[i]=1;
            }
        }
        int num=n;
        while(q.size()){
            int u=q.front();q.pop();
            vis[u]=1;
            num--;
            for(auto v:e[u]){
                if(vis[v])continue;
                if(--deg[v]==1){
                    q.push(v);
                }
            }
        }
        int r=0;
        vector<int>val(n+1,0);
        auto dfs=[&](auto&&self,int u,int fa)->void{
            int h=1;
            for(auto v:e[u]){
                if(v==fa||vis[v]==0)continue;
                self(self,v,u);
                h+=shift(val[v]);
            }
            val[u]=h;
        };
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                r=i;
                dfs(dfs,i,0);
            }
        }
        vector<int>ans;
        ans.push_back(val[r]);
        vis[r]=1;
        auto dfs1=[&](auto&&self,int u,int fa)->void{
            for(auto v:e[u]){
                if(v==fa||vis[v]==1)continue;
                ans.push_back(val[v]);
                vis[v]=1;
                self(self,v,u);
            }
        };
        dfs1(dfs1,r,0);
        bool ok=1;
        if(num&1){
            int x=ans[0];
            for(auto v:ans){
                if(v!=x){
                    ok=0;
                    break;
                }
            }
        }else{
            int len=ans.size();
            for(int i=0;i<len;i++){
                if(ans[i]!=ans[(i+2)%len]){
                    ok=0;
                    break;
                }
            }
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    mask=chrono::steady_clock::now().time_since_epoch().count();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
