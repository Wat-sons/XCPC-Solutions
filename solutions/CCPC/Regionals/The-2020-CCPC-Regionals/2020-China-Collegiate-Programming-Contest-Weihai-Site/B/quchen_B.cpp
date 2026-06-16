#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;

set<pair<int,int>>st;
vector<pair<int,int>>nd;
struct Node
{
	int x,y,dx;
};
int dis[43][5][N];

int n,m,k,q;

int dir[4][2] = {-1,0,1,0,0,1,0,-1};

bool check(int x1,int y1,int x2,int y2)
{
	
	int mnx = min(x1,x2);
	int mxx = max(x1,x2);
	int mny = min(y1,y2);
	int mxy = max(y1,y2);
	for(auto [cx,cy]:st)
	{
		if(cx>=mnx&&cx<=mxx&&cy>=mny&&cy<=mxy)
		{
			return false;
		}	
	}
	return true;
}

void bfs()
{
	
	for(int kk=0;kk<k;kk++)
	{
		int x = nd[kk].first;
		int y = nd[kk].second;
		for(int i=0;i<4;i++)
		{
			int cx = x+dir[i][0];
			int cy = y+dir[i][1];
				
			if(cx<=0||cy<=0||cx>n||cy>m)continue;
	
	
			
			for(int j=1;j<=n;j++)
			{
				for(int k2=1;k2<=m;k2++)
				{
					
					int id = (j-1)*m+k2-1;
					dis[kk][i][id] = INF;
				}
			}
			
			if(st.count({cx,cy}))continue;
			queue<pair<int,int>>q;
			q.push({cx,cy});
			
			dis[kk][i][((cx-1)*m+cy-1)]=0;
			
			while(!q.empty())
			{
				auto xx = q.front();
				q.pop();
				int x = xx.first;
				int y = xx.second;
				int id = (x-1)*m+y-1;
				for(int k3=0;k3<4;k3++)
				{
					int cx = x+dir[k3][0];
					int cy = y+dir[k3][1];
					if(cx<=0||cy<=0||cx>n||cy>m)continue;
					if(st.count({cx,cy}))continue;
					int cid = (cx-1)*m+cy-1;
					if(dis[kk][i][cid]==INF)
					{
						dis[kk][i][cid] = dis[kk][i][id]+1;
						q.push({cx,cy}); 
					}
				}
			}
		}
	}
	
}

void solve()
{
	cin>>n>>m>>k>>q;
	
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		st.insert({x,y});
		nd.push_back({x,y});
	}	
	
	
	bfs();
	
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int id1 = (a-1)*m+b-1;
		int id2 = (c-1)*m+d-1;
		
		if(check(a,b,c,d))
		{
			int ans = abs(a-c)+abs(b-d);
			cout<<ans<<'\n';
		}
		else 
		{
			int ans = INF;
			for(int i=0;i<k;i++)
			{
				int x = nd[i].first;
				int y = nd[i].second;
				for(int j=0;j<4;j++)
				{
					int cx = x+dir[j][0];
					int cy = y+dir[j][1];
					if(cx<=0||cy<=0||cx>n||cy>m)continue;
					ans = min(ans,dis[i][j][id1]+dis[i][j][id2]);
				}
			}
			if(ans==INF)cout<<-1<<'\n';
			else cout<<ans<<'\n';
		}
		
	}

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
