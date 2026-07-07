#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

int cnt = 0;
ll sum;
vector<int>cur;
void dfs(int idx,ll cnt0,ll cnt1,ll pre)
{

    if(cnt>=100)return ;
    if(cnt0>(n+2)/2||cnt1>(n+2)/2)return ;
    if(idx==n)
    {
        ll csum = cnt0*cnt1;
        cnt++;
        for(auto v:cur)
        {
            if(v==1)cout<<'r';
            else cout<<'b';
        }
        cout<<'\n';
        return ;
        
    }


    cur.push_back(0);
    dfs(idx+1,cnt0+(pre+1)%2,cnt1+(pre)%2,pre);
    cur.pop_back();

    cur.push_back(1);
    dfs(idx+1,cnt0+(pre)%2,cnt1+(pre+1)%2,pre+1);
    cur.pop_back();

}


void solve()
{
    cin>>n;

    sum = 0;


    for(int i=1;i<=n;i+=2)
    {
        sum += (n-i+1);
    }

    cout<<sum<<'\n';

    dfs(0,1,0,0);
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
