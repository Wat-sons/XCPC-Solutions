#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
string s;
bool check(ll x)
{
    ll len = 0;

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')len++;
        else 
        {
            if(len<x)
            {
                len = -x;
            }
            else if(len==x)
            {
                len = -max(x-1,0LL);
            }
            else return false;
        }
    }
    if(len>0)return false;
    return true;


}


void solve()
{
    cin>>n;
  
    cin>>s;
    s = " "+s;
    ll ans = INF;
    ll l =0, r = n;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
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
    while(t--)
    {
        solve();

    }


    return 0;
}
