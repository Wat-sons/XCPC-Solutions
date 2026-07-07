#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;


void solve()
{   
    ll p,q;
    cin>>p>>q;
    int g = gcd(p,q);
    p = p/g;
    q = q/g;
    ll x = q;
    vector<int>v;
    for(int i=2;i*i<=x;i++)
    {
        ll cur = 1;
        while(x%i==0)
        {
            cur*=i;
            x/=i;
        }
        if(cur!=1)v.push_back(cur);
    }
    if(x>1)v.push_back(x);

    int sz = v.size();

    for(int i=0;i<(1<<sz);i++)
    {
        ll a = 1;
        ll b = 1;
        for(int j=0;j<sz;j++)
        {
            if((i>>j)&1)
            {
                a*=v[j];
            }
            else b*=v[j];
        }

        if(gcd(a,b)!=1)continue;
        if(a*b==q&&(a*a+b*b)==p)
        {
            cout<<a<<' '<<b<<'\n';
            return ;
        }
    }

    cout<<0<<' '<<0<<'\n';


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
