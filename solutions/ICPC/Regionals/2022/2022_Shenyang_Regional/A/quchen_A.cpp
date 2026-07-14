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
    ll l,r;
};
Node a[N],b[N];


bool cmp(Node a,Node b)
{
    return a.l<b.l;
}

double pre[N],prelen[N];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].l>>b[i].r;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);

    int idx = 1;



    for(int i=1;i<=m;i++)
    {
        prelen[i] = prelen[i-1]+b[i].r-b[i].l;
        pre[i] = pre[i-1]+(b[i].r+b[i].l)*(b[i].r-b[i].l)/2.0;
    }

    int l=1,r=1;
    double ans = 0;

    for(int i=1;i<=n;i++)
    {
        while(a[i].r>b[r].l)r++;
        while(a[i].l>b[l].r)l++;
        ll len = 0;

        for(int j=l+1;j<r;j++)
        {
            len += b[j].r-b[j].l;
            
        }

        double res = len/3.0;
        
        

        ans += res;

    }


    printf("%.10lf\n",ans);


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
