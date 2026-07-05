#include <bits/stdc++.h>
using namespace std;
const int N=5e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const int dx = 2e6;
const ll INF = 1e18;
int n;
ll k;

ll a[N];
ll cnt[N];
ll len[N];
ll ans[N];



void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]+dx]++;
    }

    if(k==0)
    {
        ll res = 0;
        for(int i=1;i<=5e6;i++)
        {
            res = max(res,cnt[i]);
            
        }
        cout<<res<<'\n';
        return ;
    }



    for(int i=1;i<=n;i++)
    {
        len[a[i]+dx+k]++;

        ans[a[i]+dx+k] = max(ans[a[i]+dx+k],cnt[a[i]+dx+k]+len[a[i]+dx+k]);
        
        len[a[i]+dx]--;
        if(len[a[i]+dx]<0)len[a[i]+dx]=0;
    }


    ll res = 0;
    for(int i=1;i<=5e6;i++)
    {
        res = max(res,ans[i]);
    }
    cout<<res<<'\n';


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
