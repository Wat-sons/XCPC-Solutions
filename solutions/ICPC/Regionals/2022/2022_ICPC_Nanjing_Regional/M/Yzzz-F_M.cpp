#include <bits/stdc++.h>
using namespace std;
#define int long long

int get(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1;
}

void solve(){
	int n;
    cin>>n;
    vector<int>x(n+1,0),y(n+1,0);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    int ans=0;
    for(int i=0,j=1;i<n;i++){
        while(y[i]==y[j])j=(j+1)%n;
        int pre=(i+n-1)%n;
        if(y[i]<y[pre]&&y[i]<y[j]){
            if(y[i]!=y[(i+1)%n]){
                if(get(x[i]-x[pre],y[i]-y[pre],x[j]-x[i],y[j]-y[i])>0)ans++;
            }else{
                if(x[(i+1)%n]>x[i])ans++;
            }
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
