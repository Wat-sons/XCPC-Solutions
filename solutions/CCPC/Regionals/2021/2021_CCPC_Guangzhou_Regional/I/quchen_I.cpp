#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll n;

ll ans = 0;
vector<int>path;
bool vis[N];

ll qpow(ll a,ll b,ll p)
{
    ll res = 1;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            res = res*a%p;
        }
        a = a*a%p;
    }
    return res;
}

void solve()
{
    
    cin>>n;
    if(n==1)cout<<1<<'\n';
    else if(n==2)cout<<2<<'\n';
    else if(n==3)cout<<6<<'\n';
    else
    {
        ll ans = 6;
        ans = (ans*qpow(2,n-3,mod))%mod;
        cout<<ans<<'\n';
    }

    
    
    


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    path.push_back(0);
    while(t--)
    {
        solve();

    }


    return 0;
}
