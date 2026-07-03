#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;


void solve()
{   
    ll p,q;
    cin>>p>>q;
    if((p==2*q)||(p==(q*q+1))||(p==(q*q-1)))
    {
        if(p==2*q)
        {
            cout<<1<<' '<<1<<'\n';
        }
        else
        {
            cout<<q<<' '<<1<<'\n';
        }
    }
    else 
    {
        cout<<0<<' '<<0<<'\n';
    }

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
