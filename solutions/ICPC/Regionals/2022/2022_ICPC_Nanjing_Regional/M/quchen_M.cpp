#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
struct Node
{
    ll x,y;
}a[N];


ll cross(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-x2*y1;
}



void solve()
{   
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    ll ans = 0;
    int r;
    for(int l=0,r=1;l<n;l++)
    {
        while(a[l%n].y==a[r%n].y)r++;
        int pre = (l-1+n)%n;
        if(a[l].y<a[pre].y&&a[l].y<a[r%n].y)
        {
            if(a[l].y!=a[(l+1)%n].y)
            {
                
                if(cross(a[l].x-a[pre].x,a[l].y-a[pre].y,a[r%n].x-a[l].x,a[r%n].y-a[l].y)>0)ans++;
                
            }
            else if(a[l].x<a[(l+1)%n].x)ans++;
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
    // cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
