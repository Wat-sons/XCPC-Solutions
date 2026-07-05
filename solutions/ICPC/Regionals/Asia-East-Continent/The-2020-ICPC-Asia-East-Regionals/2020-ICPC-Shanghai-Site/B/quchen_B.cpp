#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;
char a[N][N];
char b[N][N];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>b[i][j];
        }
    }

    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!=b[i][j])cnt++;
        }
    }

    if(cnt<=(n*m/2))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j];
            }
            cout<<'\n';
        }
    }
    else if((n*m-cnt)<=(n*m/2))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]=='.')cout<<'X';
                else cout<<'.';
            }
            cout<<'\n';
        }

    }
    else cout<<-1<<'\n';

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
