#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll a,b;

void solve()
{   
    cin>>n>>a>>b;
    if(b<=n/2)
    {
        for(int i=1;i<=n-1;i++)cout<<"L";
        for(int i=2;i<=b;i++)cout<<"R";
    }
    else 
    {
        for(int i=1;i<=n-1;i++)cout<<"R";
        for(int i=n-1;i>=b;i--)cout<<"L";
    }

    if(a<=n/2)
    {
        for(int i=1;i<=n-1;i++)cout<<"U";
        for(int i=2;i<=a;i++)cout<<"D";
    }
    else
    {
        for(int i=1;i<=n-1;i++)cout<<"D";
        for(int i=n-1;i>=a;i--)cout<<"U";

    }
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
