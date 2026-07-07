#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = -4e18;


int n,m;
struct Node
{
	int t,v;
}a[N];


bool cmp(Node a,Node b)
{
	return a.v>b.v;
}

multiset<int>ans;
void solve()
{
	cin>>n>>m;
	
	ans.clear();
	vector<vector<int>>add(m+3);
	vector<vector<int>>del(m+3);
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
			int l = j;
			int r = min(m+1,j+a[i].t);
			add[l].push_back(a[i].v);
			del[r].push_back(a[i].v);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		for(auto v:add[i])ans.insert(v);
		
		for(auto v:del[i])
		{
			ans.erase(ans.find(v));
		}
	
		if(ans.empty())cout<<0<<' ';
		else cout<<(*ans.rbegin())<<' ';
	}
	cout<<'\n';
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
    	cout<<"Case #"<<i<<": ";
        solve();
		
    }
    return 0;
}


