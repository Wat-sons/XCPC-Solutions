#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+5;
int pow2[N],pow3[N];
int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=(pow2[n-i]*a[i]%mod*(1+(pow3[i-1]-1)*qpow(2,mod-2)%mod))%mod;
        ans=(ans+res)%mod;
    }
    cout<<ans<<'\n';

}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    pow2[0]=pow3[0]=1;
    for(int i=1;i<=2e5;i++){
        pow2[i]=(2*pow2[i-1])%mod;
        pow3[i]=(3*pow3[i-1])%mod;
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
