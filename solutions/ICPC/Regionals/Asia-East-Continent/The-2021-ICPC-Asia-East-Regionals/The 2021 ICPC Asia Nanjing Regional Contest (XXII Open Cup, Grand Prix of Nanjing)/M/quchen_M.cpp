#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll a[N];

bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<a[1]<<'\n';
        return ;
    }
    
    sort(a+1,a+1+n,cmp);
    ll ans = 0;
    if(a[1]<=0&&a[n]<=0)
    {
        for(int i=2;i<=n;i++)
        {
            ans+=abs(a[i]);
        }

        ans += a[1];
    }
    else 
    {
        for(int i=1;i<=n-1;i++)
        {
            ans+=abs(a[i]);
        }

        ans -= a[n];
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
