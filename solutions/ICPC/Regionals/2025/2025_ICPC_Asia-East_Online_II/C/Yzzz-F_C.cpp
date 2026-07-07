#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int S;
    cin>>S;
    int f1,f2,f3,f4,f5,f6,f7;
    cin>>f1>>f2>>f3>>f4>>f5>>f6>>f7;
    int l=0,r=S/3,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        bool ok=true;
        if(f1+f3+f5+f7<mid)ok=false;
        if(f2+f3+f6+f7<mid)ok=false;
        if(f4+f5+f6+f7<mid)ok=false;
        if(f1>S-2*mid)ok=false;
        if(f2>S-2*mid)ok=false;
        if(f4>S-2*mid)ok=false;
        if(ok){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
