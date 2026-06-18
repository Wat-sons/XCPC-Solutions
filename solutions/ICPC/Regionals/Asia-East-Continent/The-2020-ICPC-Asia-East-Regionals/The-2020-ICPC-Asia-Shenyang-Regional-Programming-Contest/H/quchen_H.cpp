#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;

ll n,m,r;
ll dp[N];

struct Node
{
    ll p,q;
}a2[N];

bool cmp(Node a,Node b)
{
    return a.p<b.p;
}

ll cnt[N];
ll pre[N];
ll idx = 0;
ll a[N],b[N],c[N];


void solve()
{
    cin>>n>>m>>r;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }

    for(int i=1;i<=m;i++)
    {
        cin>>a2[i].p>>a2[i].q;
    }
    sort(a2+1,a2+1+m,cmp);

    for(int i=1;i<=m;i++)
    {
        while(a2[i].q--)cnt[++idx]=a2[i].p;
    }

    for(ll i=1;i<=idx;i++)
    {
        dp[i] = i*r;
        pre[i]=1;

    }


    for(int i=1;i<=idx;i++)
    {
        for(int j=1;j<=n;j++)
        {
            while(cnt[pre[j]]+a[j]-1<cnt[i]||pre[j]+b[j]-1<i)pre[j]++;
            dp[i] = min(dp[i],dp[pre[j]-1]+c[j]);
        }
    }

    cout<<dp[idx]<<'\n';
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
