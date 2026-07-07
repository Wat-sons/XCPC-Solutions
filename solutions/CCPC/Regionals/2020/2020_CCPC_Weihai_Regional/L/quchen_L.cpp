#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;

int n,k;
int a[N];
bool vis[N];
int idx = 0;
int p[N];
double v[N];
double dp[N];

void solve()
{
	cin>>n;
	printf("%.10lf\n",dp[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=2;i<=N-10;i++)
    {
		if(vis[i])continue;
		vis[i] = true;
		p[++idx]=i;
		v[idx] = log(i);
		for(int j=2*i;j<=N-10;j+=i)
		{
			vis[j]=true;
		}
	}
	for(int i=1;i<=idx;i++)
	{
		for(int j=N-10;j>=p[i];j--)
		{
			double tt = 1.0;
			int cur = p[i];
			while(cur<=j)
			{
				dp[j] = max(dp[j],dp[j-cur]+tt*v[i]);
				cur*=p[i];
				tt++;
			}
		}
	}
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
