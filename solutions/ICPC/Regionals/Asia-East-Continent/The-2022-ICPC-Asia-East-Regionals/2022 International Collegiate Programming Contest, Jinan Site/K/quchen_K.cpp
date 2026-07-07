#include <bits/stdc++.h>
using namespace std;
const int N=6e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll a[N],pos[N];

void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        pos[a[i]]=i;
    }
    int idx = n+1;

    ll ans = 1;
    for(int i=1;i<=n;i++)
    {
        if(pos[i]<idx)
        {
            idx = pos[i];
        }
        else 
        {
            idx = pos[i];
            ans++;
            // cout<<i<<'\n';
        }
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
