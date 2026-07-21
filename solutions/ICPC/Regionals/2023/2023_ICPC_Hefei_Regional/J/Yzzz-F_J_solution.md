Tags:Dijkstra,枚举

Auther:Yzzz-F

题解：

我们枚举边（u,v,w）为最大边，那么第二大的边一定是max( 1->u, v->n  )  和max(1->v, u->n) 二者的最小值，因此，我们在1和n分别跑一遍dijkstra，维护路径上的最小的最大值，然后枚举每一条边即可



代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>e(n+1);
    vector<array<int,3>>edges;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    vector<int>d1(n+1,1e18),dn(n+1,1e18);
    auto dijkstra=[&](int x,vector<int>&d)->void{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool>vis(n+1,0);
        d[x]=0;
        q.push({0,x});
        while(q.size()){
            auto u=q.top();q.pop();
            int id=u.second,val=u.first;
            for(auto [v,w]:e[id]){
                if(d[v]>max(d[id],w)){
                    d[v]=max(d[id],w);
                    q.push({d[v],v});
                }
            }
        }
    };
    dijkstra(1,d1);
    dijkstra(n,dn);
    int ans=1e18;
    for(auto [u,v,w]:edges){
        if(w>=d1[u]&&w>=dn[v]){
            ans=min(ans,w+max(d1[u],dn[v]));
        }
        if(w>=d1[v]&&w>=dn[u]){
            ans=min(ans,w+max(d1[v],dn[u]));
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}

```

