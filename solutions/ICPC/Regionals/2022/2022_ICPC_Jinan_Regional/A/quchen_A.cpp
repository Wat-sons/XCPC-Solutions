#include <bits/stdc++.h>
using namespace std;
const int N=6e2+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;
ll a[N];
ll b[30*N];
ll cnt = 0;

void solve()
{
    cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ll x = a[i];
        while(x)
        {
            b[++cnt] = x;
            x/=2;
        }

    }

    b[++cnt]=0;

    ll ans = INF;
    for(int i=1;i<=cnt;i++)
    {
        vector<ll>v;
        ll sum = 0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<b[i])
            {
                v.push_back(abs(b[i]-a[j]));
            }
            else
            {
                ll cur = INF;
                ll stp = 0;
                ll x = a[j];
                while(x/2>b[i])
                {
                    x/=2;
                    stp++;
                }
                cur = min(stp+abs(x-b[i]),cur);
                x/=2;
                stp++;
                cur = min(stp+abs(x-b[i]),cur);
                
                v.push_back(cur);
            }
            
        }
        sort(v.begin(),v.end());
        for(int j=0;j<n-m;j++)
        {
            sum+=v[j];
        }
        ans = min(ans,sum);
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
