#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;

ll n,m;


struct Node
{
	ll x,v;
	
}a[N];

bool cmp(Node a,Node b)
{
	return a.v<b.v;
}

ll qpow(ll a,ll b,ll p)
{
	ll res=1;
	for(;b;b>>=1)
	{
		if(b&1)res = res*a%p;
		a=a*a%p;
	}
	return res;
}

ll b[N];

void solve()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].x;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)b[i]=a[i].x;
	ll ans = 1;
	ll r;
	for(int l=1;l<=n;l=r+1)
	{
		r = l;
		while(r<n&&((a[r+1].v-a[r].v)<=32)&&(b[r]>>(a[r+1].v-a[r].v)))
		{
			b[r+1]+=b[r]>>(a[r+1].v-a[r].v);
			r++;
		}
		
		
		for(int i=r;i>l;i--)
		{
			a[i-1].x=(a[i-1].x+a[i].x*qpow(2,a[i].v-a[i-1].v,mod))%mod;
		}
		ans = ans*(a[l].x+1)%mod;
	}
	
	
	cout<<ans<<'\n';
	
	

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

