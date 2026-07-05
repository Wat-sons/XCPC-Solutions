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
	ll x;
	cin>>x;
	
	if(x%2==1)
	{
		ans = 1;
	}
	else  
	{	
		if(x%4==0)
		{
			ans = 2;
		}
		else  
		{
			if(x%6==0)
			{
				if(x==6)ans=-1;
				else ans = 2;
			}
			else 
			{
				if(x%4==2)ans = 4;
				
				if(x%6==2)
				{
					ll r = x/6;
					if((2*r-1)%3!=0)ans=3;		
				}

				if(x%6==4)
				{
					ll r = x/6;
					if((2*r)%3!=0)ans=3;		
				}
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
        cout<<"Case #"<<i<<": "<<ans<<'\n';
    }
    return 0;
}
