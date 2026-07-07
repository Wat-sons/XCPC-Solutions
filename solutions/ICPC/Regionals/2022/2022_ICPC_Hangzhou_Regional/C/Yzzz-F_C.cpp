#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[3005][3005][2];
const int INF=1e18;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j][0]=-INF;
			dp[i][j][1]=-INF;
		}
	}
	vector<int>p(n+1,0);
	int sum=0;
	vector<vector<int>>w(n+1,vector<int>(11,0));
	for(int i=1;i<=n;i++){
		cin>>p[i];
		sum+=p[i];
		for(int j=1;j<=p[i];j++){
			cin>>w[i][j];
		}
	}
	for(int i=0;i<=n;i++){
		dp[i][0][0]=0;
	}
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=k;j>=0;j--){
			dp[i][j][0]=max(dp[i-1][j][0],dp[i][j][0]);
			dp[i][j][1]=max(dp[i-1][j][1],dp[i][j][1]);
			for(int o=1;o<=p[i];o++){
				if(o==p[i]){
					if(o+j>k)continue;
					dp[i][j+o][0]=max(dp[i][j+o][0],dp[i-1][j][0]+w[i][p[i]]);
					dp[i][j+o][1]=max(dp[i][j+o][1],dp[i-1][j][1]+w[i][p[i]]);
				}else {
					if(o+j>k)continue;
					dp[i][j+o][1]=max(dp[i][j+o][1],dp[i-1][j][0]+w[i][o]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			ans=max(ans,dp[i][j][0]);
			if(j==k)ans=max(ans,dp[i][j][1]);
		}
	}
	cout<<ans<<'\n';



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
/*




*/
