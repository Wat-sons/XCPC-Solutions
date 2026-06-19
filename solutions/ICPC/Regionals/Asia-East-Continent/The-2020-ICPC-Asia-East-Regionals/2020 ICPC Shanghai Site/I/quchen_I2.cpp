#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
const double PI = acos(-1);
ll n,m;
double dis1[N];
double dis2[N];


void solve()
{
    cin>>n>>m;

    double ans = 0;
    double d = 0.0;

    for(int i=1;i<m;i++)
    {
        d+=min(2.0,PI/m*i);
    }

    d*=2;
    d+=2;

    dis1[1] = dis2[1] = d;

    for(int i=2;i<=n;i++)
    {
        dis1[i] = dis1[1]*i;

        dis2[i] = dis2[i-1]+dis1[i]+2*m*(i-1);

    }

    ans+=2*(m>1)*m*n*(n+1)/2;


    for(int i=1;i<=n;i++)
    {
        ans += 2*m*dis2[i]- m * dis1[i] ;
    }
    

   
    printf("%.10lf\n",ans);

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

