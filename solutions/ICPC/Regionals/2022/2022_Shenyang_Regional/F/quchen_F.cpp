#include <bits/stdc++.h>
using namespace std;
const int N=3e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll n,m;

vector<int>ans;
ll pre[N];
ll calc(ll x,ll y)
{
    ll l=1,r=y;
    ll ans = 1;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(mid*(mid+1)/2<=x-(y-mid))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

void get_res(ll x,ll y)
{
    while(y)
    {
        ll cur = calc(x,y);
        y -= cur;
        x -= cur*(cur+1)/2;
        ans.push_back(cur);
    }

}

void solve()
{   
    cin>>n>>m;
    ans.clear();
    if(((n+1)*n/2)%2==0)
    {
        ll rst = (n+1)*n/2/2;
        ll rst2 = n;
        get_res(rst,rst2);
        // for(auto v:ans)cout<<v<<' ';
        vector<vector<int>>res(n+1,vector<int>(m+1,0));
        int cur = 1;
        int pre = 0;
        for(auto v:ans)
        {
            for(int i=1;i<=v;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    res[pre+i][j] = cur;
                }
            }
            pre += v;
            cur ^= 1;
        }

        cout<<"Yes\n";

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<res[i][j]<<' ';
            }
            cout<<'\n';
        }

    }
    else if(((m+1)*m/2)%2==0)
    {
        cout<<"Yes\n";
        ll rst = (m+1)*m/2/2;
        ll rst2 = m;
        get_res(rst,rst2);
        // for(auto v:ans)cout<<v<<' ';
        vector<vector<int>>res(n+1,vector<int>(m+1,0));
        int pre = 0;
        int cur = 1;

        for(auto v:ans)
        {
            
            for(int j=1;j<=v;j++)
            {
                for(int i=1;i<=n;i++)
                {
                    res[i][pre+j] = cur;
                }
            }
            cur^=1;
            pre+=v;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<res[i][j]<<' ';
            }
            cout<<'\n';
        }


    }
    else
    {
        cout<<"No\n";
        return ;
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll i=1;i<=N-10;i++)
    {
        pre[i] = i*(i+1)/2;
    }
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
