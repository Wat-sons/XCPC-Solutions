#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

vector<pair<int,ll>>e[N];
set<int>st[4];
ll sz[N][4];
ll sz2[4];
ll ans12 = 0;
ll ans23 = 0;
ll ans13 = 0;
void dfs(int u,int fa)
{	
	
	for(int i=1;i<=3;i++)
	{
		if(st[i].count(u))sz[u][i]=1;
	}
	
	
	for(auto [v,w]:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		for(int i=1;i<=3;i++)
		{
			sz[u][i]+=sz[v][i];
		}
	}
		
	for(auto [v,w]:e[u])
	{
		if(v==fa)continue;
		
		ans12 += (sz[v][1]*(sz2[2]-sz[v][2])+sz[v][2]*(sz2[1]-sz[v][1]))*w;
		ans23 += (sz[v][2]*(sz2[3]-sz[v][3])+sz[v][3]*(sz2[2]-sz[v][2]))*w;
		ans13 += (sz[v][1]*(sz2[3]-sz[v][3])+sz[v][3]*(sz2[1]-sz[v][1]))*w;
	}
	
}

void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=3;i++)
    {
        int m;
        cin>>m;
        sz2[i]=m;
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            st[i].insert(x);
        }
		
    }

	dfs(1,0);

	double res12 = ans12*1.0/(sz2[1]*sz2[2]);
	double res23 = ans23*1.0/(sz2[2]*sz2[3]);
	double res13 = ans13*1.0/(sz2[1]*sz2[3]);
	double res = (res12+res13+res23)*1.0/2;
	printf("%.10lf\n",res);	
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
    {
        solve();

    }
    return 0;
}
