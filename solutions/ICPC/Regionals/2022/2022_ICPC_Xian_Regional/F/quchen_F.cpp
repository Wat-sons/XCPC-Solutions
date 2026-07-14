#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll c1,c2;
ll cnt[28];
void solve()
{
    cin>>n>>c1>>c2;
    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<26;j++)cnt[j]=0;
        for(int j=0;j<s.size();j++)cnt[s[j]-'A']++;

        for(int j=0;j<26;j++)
        {
            res += min({(cnt[j]/2)*c2+(cnt[j]%2)*min(c1,c2),cnt[j]*c1,cnt[j]*c2});   
        }

    }

    cout<<res<<'\n';


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
