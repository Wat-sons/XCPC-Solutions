#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 5e9;


ll ans = 0;
ll a[N];
int n;

bool check(ll x)
{
	ll cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x)continue;
		else cnt+=x-a[i];
	}
	
	return cnt<=x;
}

void solve()
{
	cin>>n;
	
	ans = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	ll l=1,r=INF;
	while(l<=r)
	{
		ll mid = (l+r)/2;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	ans++;
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
        cout<<"Case #"<<i<<": "<<ans<<'\n';
		
    }
    return 0;
}
