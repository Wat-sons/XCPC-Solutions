#include <bits/stdc++.h>
using namespace std;
const int N=3e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
const ll INF = 1e18;
int n;
ll c;
bool check(ll x)
{
    i128 y = sqrtl(x);
    while(y*y<x)y++;
    while(y*y>x)y--;
    return y*y==x;
}

void solve()
{
    cin>>c;
    if(c==1)
    {
        cout<<"no\n";
        return ;
    }
    if(check(c))
    {
        cout<<"yes\n";
        return ;
    }
    for(i128 i=2;(i128)i*i*i<=c;i++)
    {
        i128 p2 = i*i;
        if(c%p2==0)
        {
            cout<<"yes\n";
            return ;
        }
        if(c%i==0&&check((ll)(c/i)))
        {
            cout<<"yes\n";
            return ;
        }
    }
    cout<<"no\n";
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
