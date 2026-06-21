#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const double INF = 1e18;
const double eps = 1e-8;

ll n,m;
long double p;

long double qpow(long double a,ll b)
{
    long double res = 1.0;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            res = res*a;
        }
        a = a*a;
    }
    return res;
}

bool check(ll k)
{
    long double e1 = (k*1.0*n+m)/(1.0-qpow((10000.0-p)/10000.0,k));
    long double e2 = ((k+1)*1.0*n+m)/(1.0-qpow((10000.0-p)/10000.0,k+1));

    return e1>=e2;

}


void solve()
{
    cin>>n>>m>>p;
    ll l=1,r=INT_MAX;
    ll ans = 1;
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

    // cout<<ans<<'\n';

    ans++;
    long double res1 = (ans*1.0*n+m)/(1.0-qpow((10000-p)/10000.0,ans));
    ans--;
    long double res2 = (ans*1.0*n+m)/(1.0-qpow((10000-p)/10000.0,ans));
    ans--;
    long double res3 = (ans*1.0*n+m)/(1.0-qpow((10000-p)/10000.0,ans));

    long double res = min({res1,res2,res3});
    printf("%.10Lf\n",res);
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
