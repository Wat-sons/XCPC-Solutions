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
    ll a, b, c;
    cin>>a>>b>>c;

    if (a==b&&b==c) 
    {
        if (a == 0) 
        {
            cout<<"YES\n";
            cout << 1 << " " << 1 << " " << 1 << "\n";
        } 
        else 
        {
            cout<<"NO\n";
        }
        return ;
    }

    ll x=0,y=0,z=0;
    ll i,j;
    cout<<"YES\n";
    if(a>c)
    {
        x = a;
        z = c+((c<=b)?((b-c)/a+1):0)*a;
        y = b+((b<=a)?((a-b)/z+1):0)*z;

    }
    else if(b>a)
    {
        y = b;
        x = a+((a<=c)?(c-a)/b+1:0)*b;
        z = c+((c<=b)?(b-c)/x+1:0)*x;
    }
    else if(c>b)
    {
        z = c;
        y = b+((b<=a)?((a-b)/c+1):0)*c;
        x = x = a+((a<=c)?(c-a)/y+1:0)*y;

    }
    cout<<x<<' '<<y<<' '<<z<<'\n';
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

