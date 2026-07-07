#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

struct Node
{
    ll v, idx;
}a[N];

ll pos[N];
bool cmp(Node a,Node b)
{
    if(a.v!=b.v)return a.v<b.v;
    else return a.idx<b.idx;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].idx = i;
    }

    sort(a+1,a+1+n,cmp);

    for(int i=1;i<=n;i++)
    {
        pos[a[i].idx]=i;
    }

    ll cur = 0;
    ll cnt = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        cur = max(cur,pos[i]);
        cnt++;
        if(cur==cnt)ans++;
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
