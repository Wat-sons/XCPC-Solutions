#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = -4e18;
ll n,m;
ll ans[N];
 
struct Node
{
	ll t,v;
}a[N];
ll fa[N];
bool cmp(Node a,Node b)
{
	return a.v>b.v;
}

ll find(ll x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(ll x)
{
	fa[x] = find(x+1);
	
}
bool vis[N];


void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m+2;i++)
	{
		ans[i]=0;
		fa[i]=i;
		
	}
	
	set<int>vis;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t>>a[i].v;
		
		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(vis.count(a[i].t))continue;
		vis.insert(a[i].t);
		for(int j=1;j<=m;j+=2*a[i].t)
		{
			ll l = j;
			ll r = min(m,j+a[i].t-1);
			
			int pos = find(l);
			while(pos<=r)
			{
				ans[pos]=a[i].v;
				merge(pos);
				pos = find(pos);
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
        cout<<"Case #"<<i<<": ";
        for(int j=1;j<=m;j++)
        {
			cout<<ans[j]<<' ';  
		}
		cout<<'\n';
		
    }
    return 0;
}
