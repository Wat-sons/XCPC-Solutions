#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll l,r;


ll calc(ll x)
{
    ll res = 0 ;
    while(x)
    {
        res+=x%3;
        res++;
        x/=3;
    }
    return res;

}


ll get_v(vector<ll>x)
{
    ll res = 0;
    for(int i=0;i<x.size();i++)
    {
        res = res*3+x[i];
    }
    return res;
}


void solve()
{
    cin>>l>>r;

    ll res = calc(r);

    vector<ll>a;
    ll x = r;
    while(x)
    {
        a.push_back(x%3);
        x/=3;
    }
    reverse(a.begin(),a.end());
    n = a.size();

    for(int i=0;i<n;i++)
    {
        vector<ll>b = a;
        if(b[i]==0)continue;
        b[i]--;
        for(int j=i+1;j<n;j++)
        {
            b[j]=2;
        }

        ll v = get_v(b);
        ll ans = calc(v);
        if(v>=l&&v<=r)
        {
            res = max(ans,res);
        }
    }


    cout<<res<<'\n';


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
