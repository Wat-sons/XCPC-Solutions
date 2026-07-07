#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
int k;

void solve()
{
    cin>>n>>k;
    if(n!=1&&k==1)
    {
        cout<<"No\n";
        return ;
    }
    else if(n==k)
    {
        cout<<"Yes\n";
        return ;
    }


    if(k%2==0)cout<<"Yes\n";
    else 
    {
        
        ll cnt1 = (n+1)/2;
        ll cnt0 = n/2;
        ll num1 = (k+1)/2;
        ll num0 = k/2;
        ll x = n/k;
        ll r1 = cnt1-num1*x;
        ll r0 = cnt0-num0*x;
        if(r1<=num1&&r0<=num0&&r1>=0&&r0>=0)
        {
        cout<<"Yes\n";
        }
        else cout<<"No\n";
    }


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
