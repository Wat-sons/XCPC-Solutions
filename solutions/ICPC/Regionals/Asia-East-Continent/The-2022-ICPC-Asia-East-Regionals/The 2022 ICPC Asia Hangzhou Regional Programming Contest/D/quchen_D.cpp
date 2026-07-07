#include <bits/stdc++.h>
using namespace std;
const int N=3e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll a[N];

void solve()
{
    cin>>n;
    double sum =0.0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        
        sum+=a[i];
    }

    double dx = sum/(n+1);
    printf("%.10lf ",2*dx);
    for(int i=2;i<=n;i++)
    {
        printf("%.10lf ",dx);
    }

    printf("\n");


    

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
