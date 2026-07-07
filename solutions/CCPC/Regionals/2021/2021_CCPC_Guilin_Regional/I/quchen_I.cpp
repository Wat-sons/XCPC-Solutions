#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
string s;

void solve()
{
    cin>>n;
    cin>>s;
    s = " "+s;
    int cnt = 0;
    ll ans = 0;
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='0')
        {
            cnt++;
            continue;
        }
        else
        {
            if(cnt==0)cnt++;
            else ans+=i,cnt--;
        }
    }
    cout<<ans<<'\n';
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
