#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=a*a%mod;
    }
    return ans;
}
const int N=1005;
int fac[N],inv[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=1000;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    inv[1000]=qpow(fac[1000],mod-2);
    for(int i=999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int n,m,k;
    cin>>n>>m;
    vector<int>y(n,0);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
    }
    for(int i=1;i<n;i++){
        cout<<"? 1 "<<n<<' '<<i<<endl;
        cin>>y[i];
        y[i]=(y[i]%mod+mod)%mod;
    }
    cout<<"!"<<endl;
    cin>>k;
    k=(k%mod+mod)%mod;
    vector<int>pre(n,1);
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]*((k-(i-1))%mod+mod)%mod;
    }
    vector<int>suf(n,1);
    for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]*((k-(i+1))%mod+mod)%mod;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int res=y[i]*pre[i]%mod;
        res=res*suf[i]%mod;
        res=res*inv[i]%mod;
        res=res*inv[n-1-i]%mod;
        if((n-1-i)&1){
            res=(mod-res)%mod;
        }
        
        ans=(ans+res)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
