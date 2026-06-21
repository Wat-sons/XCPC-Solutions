#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;
ll a[N],b[N];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }


    sort(a+1,a+1+n);
    sort(b+1,b+1+m);


    ll ans = 0;

        
    ll l=1,r=1; 

    while(r<=n&&a[r]<b[1])r++;
    ans = max(ans,r-l);

    for(int i=1;i<m;i++)
    {
        while(l<=n&&a[l]<=b[i])
        {
            l++;
        }

        while(r<=n&&a[r]<b[i+1])r++;

        ans = max(ans,r-l);
        
    }

    while(l<=n&&a[l]<=b[m])l++;
    ans = max(ans,n+1-l);

    if(ans==0)
    {
        cout<<"Impossible\n";
    }
    else cout<<ans<<'\n';


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
