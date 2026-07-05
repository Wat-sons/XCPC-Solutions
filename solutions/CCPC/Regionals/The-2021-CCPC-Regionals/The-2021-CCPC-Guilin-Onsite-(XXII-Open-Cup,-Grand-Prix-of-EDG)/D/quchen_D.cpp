#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
int pos[N];
ll a[N],b[N];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;

        
    }

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    vector<pair<int,int>>p;


    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i])continue;
        else if(a[i]<b[i]) 
        {
            cout<<-1<<'\n';
            return ;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>=b[i]&&a[j]<a[i])
            {
                swap(a[i],a[j]);
                p.push_back({i,j});
            }
        }
    }

    cout<<p.size()<<'\n';
    for(auto [a,b]:p)
    {
        cout<<a<<' '<<b<<'\n';
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
