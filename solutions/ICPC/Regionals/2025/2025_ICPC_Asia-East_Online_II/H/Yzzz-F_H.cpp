#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
const int inv2=499122177;  
const int N=3005;
int fac[N];

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>e(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int>cnt(n+1,0);
    vector<int>d(n+1,0);
    
    auto dfs=[&](auto self,int u,int fa)->void{
        d[u]=d[fa]+1;
        for(auto v:e[u]){
            if(v==fa)continue;
            self(self,v,u);
        }
        cnt[d[u]]++;       
    };
    
    for(int i=1;i<=n;i++){
        d[0]=0;
        dfs(dfs,i,0);
    }
    
    int ans=0;
    for(int i=2;i<=n;i++){
        cnt[i]=cnt[i]*inv2%mod;
        if(cnt[i]){
            int val=(fac[i]-2*fac[i-1]%mod+fac[i-2]+mod)%mod;
            ans=(ans+cnt[i]*val)%mod;
        }
    }
    cout<<(ans+1)%mod<<'\n';  
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0]=1;
    for(int i=1;i<=3000;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
