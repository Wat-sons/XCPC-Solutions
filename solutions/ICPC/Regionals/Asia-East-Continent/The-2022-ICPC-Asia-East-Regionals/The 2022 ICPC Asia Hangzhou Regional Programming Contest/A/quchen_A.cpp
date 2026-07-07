#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll n,m;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b,a%b,y,x);
    y -= x*(a/b);
    return g;
}

void solve()
{
    cin>>n>>m;
    ll sum = 0;
    for(int i=1;i<=n;i++)
    {
        ll v;
        cin>>v;
        sum+=v;
    }

    ll x1=1,y1=0,x2=1,y2=0;
    ll g = exgcd(exgcd(n,(n+1)*n/2,x1,y1),m,x2,y2);
    sum%=m;
    ll k = (m-sum+g-1)/g;
    
    ll rst = (k*g%m+sum)%m;

    cout<<rst<<'\n';
    x1 = (x1*x2%m*k%m+m)%m;
    y1 = (y1*x2%m*k%m+m)%m;
    cout<<x1<<' '<<y1<<'\n';


    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
