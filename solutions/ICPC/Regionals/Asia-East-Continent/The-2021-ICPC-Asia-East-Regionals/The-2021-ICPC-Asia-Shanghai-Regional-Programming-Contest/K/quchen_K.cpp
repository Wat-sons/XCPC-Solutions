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
    cin>>n;
    if(n==3)
    {
        cout<<"Unlucky\n";
        return ;
    }
    if(n%2==1)
    {
        cout<<10001;
        n-=5;
    }
    for(int i=1;i<=n/4;i++)cout<<"1001";
    ll r = n%4;
    for(int i=1;i<=r/2;i++)cout<<"10";
    

    
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
