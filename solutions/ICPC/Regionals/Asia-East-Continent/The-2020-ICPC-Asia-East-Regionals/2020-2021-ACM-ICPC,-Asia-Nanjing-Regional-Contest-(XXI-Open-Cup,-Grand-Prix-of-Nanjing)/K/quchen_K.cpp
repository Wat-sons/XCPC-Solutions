#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,k;


void solve()
{
    cin>>n>>k;
    if(k==0)
    {
        cout<<-1<<'\n';
    }
    else 
    {
        for(int i=1;i<=k-1;i++)
        {
            cout<<i+1<<' ';
        }
        cout<<1<<' ';

        for(int i=k+1;i<=n;i++)
        {
            cout<<i<<' ';
        }
        cout<<'\n';
    }

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
