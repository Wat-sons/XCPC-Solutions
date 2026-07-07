#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll dp[N];
bool vis[N];
int mv[10]={1,10,100,1000,11,110,1100,1110,111,1111};

void bfs()
{
    
    dp[0]=0;
    queue<int>q;
    q.push(0);
    vis[0] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<10;i++)
        {
            ll nxt =  0;
            ll nxt2 = 0;
            ll c = 1000;
            for(int k=0;k<4;k++)
            {   
                ll cur = u/c;
                cur%=10;
                ll cur2 = mv[i]/c;
                cur2%=10;
                int num1 = (cur+cur2+10)%10;
                int num2 = (cur-cur2+10)%10;
                nxt = nxt*10+num1;
                nxt2 = nxt2*10+num2;
                c/=10;
            }
            if(!vis[nxt])
            {
                dp[nxt] = dp[u]+1;
                q.push(nxt);
                vis[nxt]=true;
            }
            if(!vis[nxt2])
            {
                dp[nxt2] = dp[u]+1;
                q.push(nxt2);
                vis[nxt2]=true;
            }
        }

    }


}


void solve()
{
    string a,b;
    cin>>a>>b;
    int num1=0;
    int num2 = 0;
    int res = 0;
    for(int i=0;i<4;i++)
    {
        num1 = a[i]-'0';
        num2 = b[i]-'0';
        res=res*10+(num1-num2+10)%10;
    }
    cout<<dp[res]<<'\n';

    // cout<<res<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bfs();

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
