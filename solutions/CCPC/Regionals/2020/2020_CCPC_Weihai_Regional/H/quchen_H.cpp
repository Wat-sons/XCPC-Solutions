#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m,s;


void solve()
{ 
    cin>>n>>m>>s;
   
    vector<int>ans(m+1,0);    
    vector<set<int>>st(n+1);
    vector<int>cnt(n+1,0);
    while(s--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            st[y].insert(x);
            ans[x]-=cnt[y];
        }
        else if(t==2)
        {
            ans[x]+=cnt[y];
            st[y].erase(x);
        }
        else 
        {
            cnt[y]++;
            ans[x]--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(auto v:st[i])ans[v]+=cnt[i];
    }

    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<'\n';
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
