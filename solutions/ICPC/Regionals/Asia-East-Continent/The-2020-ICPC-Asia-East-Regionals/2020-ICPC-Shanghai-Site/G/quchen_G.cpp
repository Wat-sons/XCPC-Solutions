#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll n;


void solve()
{
    cin>>n;
    ll res = n*(n-1)/2;
    ll m3 = n/3;
    res -= (n-m3)*(n-m3-1)/2;
    cout<<res<<'\n';  

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
