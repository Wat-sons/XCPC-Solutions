#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n,k,m,c,d;
    cin>>n>>k>>m>>c>>d;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0,r=2e18;
    int ans=0;
    auto check=[&](int mid)->bool{
        vector<int>df(n+2,0);
        vector<int>w(n+2,0);
        int rp=n-m+1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=mid){
                w[i]=w[i-1];
                cnt++;
                continue;
            }else {
                if(d==0){
                    w[i]=w[i-1];
                    if(a[i]+c>=mid){
                        w[i]+=1;
                    }
                }else {
                    int num=a[i]+c+d*i-mid;
                    int len=num/d;
                    if(num<0){
                        len=(num-d+1)/d;
                    }
                    int ll=i-m+1;
                    int pl=max(ll,1LL);
                    int pr=min(len,rp);
                    pr=min(pr,i);
                    if(pl<=pr){
                        df[pl]++;
                        df[pr+1]--;
                    }

                }
            }
        }
        int maxn=0;
        if(d==0){
            for(int i=m;i<=n;i++){
                maxn=max(maxn,w[i]-w[i-m]);

            }
            return cnt+maxn>=k;
        }else {
            int cur=0;
            for(int i=1;i<=n-m+1;i++){
                cur+=df[i];
                maxn=max(maxn,cur);
            }
            return maxn+cnt>=k;
        }
    };
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t=1;
	// cin>>t;
    while(t--)solve();
    return 0;
}
