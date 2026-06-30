#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
const ll M = 1e9;
int n;

ll ans = 0;
vector<ll>p;
bool vis[N];
ll a,b;

unordered_map<ll,ll>dp;


ll f(ll x,ll g,vector<ll>p2)
{   
    if(x==1)return 0;
    if(g==1)return x-1;
    if(dp[x*M+g])return dp[x*M+g];
    ll res = x-1;
    for(int i=0;i<p2.size();i++)
    {
        ll cp = p2[i];

        vector<ll>tmp=p2;
        tmp.erase(tmp.begin()+i);
        int y = x/cp;
        if(y)res = min(res,f(y,g/cp,tmp)+x-y*cp+1);
        y = (x+cp-1)/cp;
        res = min(res,f(y,g/cp,tmp)+y*cp-x+1);
    }
    dp[x*M+g] = res;
    return res;
}

void solve()
{   
    vector<ll>p2;
    cin>>a>>b;
    if(a>b)swap(a,b);
    ll x = b-a;
    for(ll j=1;p[j]*p[j]<=x;j++)
    {
        while(x%p[j]==0)
        {
            p2.push_back(p[j]);
            x/=p[j];
        }

    }
    if(x>1)p2.push_back(x);

    ll g = b-a;
    cout<<f(a,g,p2)<<'\n';
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p.push_back(1);
    for(ll i=2;i<=N-10;i++)
    {
        if(vis[i])continue;
        vis[i] = true;
        p.push_back(i);
        for(ll j=2*i;j<=N-10;j+=i)
        {
            vis[j] = true;
        }
    }
    
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
