#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll dp[6];
string s2 = "edgnb";
void solve()
{
    string s;
    cin>>s;
    s = " "+s;
    n = s.size();
    int ans = 0;
    for(int i=5;i<=n;i++)
    {   
        bool ok = true;
        for(int j=0;j<5;j++)
        {
            if(s[i-4+j]==s2[j])continue;
            else ok = false;
        }
        if(ok)ans++;
    }
    cout<<ans<<'\n';
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
