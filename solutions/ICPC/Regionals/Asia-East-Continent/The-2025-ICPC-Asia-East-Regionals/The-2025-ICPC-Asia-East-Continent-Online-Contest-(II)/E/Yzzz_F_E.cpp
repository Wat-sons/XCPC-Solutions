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
void solve(){
    int n,m;
    cin>>n>>m;
    int ans=qpow((qpow(2,m)-1), n-1);
    if(n%2==0){
        ans+=qpow(1-qpow(2,m),n/2);
    }
    while(ans<0)ans+=mod;
    ans%=mod;
    cout<<ans<<'\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
