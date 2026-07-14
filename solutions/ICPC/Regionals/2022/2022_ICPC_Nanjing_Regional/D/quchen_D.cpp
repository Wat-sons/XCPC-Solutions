#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,k,m;
ll c,d;
ll dx[N],a[N];
ll pre[N];
bool check(ll x)
{
    ll cnt = 0;
    for(int i=1;i<=n;i++)pre[i]=0,dx[i]=0;
  
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x)cnt++;
        else
        {
            ll ddx = x-a[i];
            ll l = max(i-m+1LL,1LL);
            ll r = l-1;
            if(ddx<=c)
            {
                r = i;
            }
            else if(d!=0)
            {
                ddx-=c;
                ll dis = (ddx+d-1)/d;
                r = i-dis;
            }
            r = max(0LL,r);
            if(l>r)continue;
            dx[l]++;
            dx[r+1]--;
            
        }    
    }   


    for(int i=1;i<=n-m+1;i++)
    {
        pre[i] = pre[i-1]+dx[i];
        if(pre[i]+cnt>=k)return true;
    }

    return cnt>=k;

}


void solve()
{
    cin>>n>>k>>m>>c>>d;
    ll mx = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx = max(mx,a[i]);
    }

    ll l=0,r=mx+c+d*(m-1);
    ll ans = 0;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+1;
            ans = mid;
        }
        else r = mid-1;
    }

    cout<<ans<<'\n';

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
