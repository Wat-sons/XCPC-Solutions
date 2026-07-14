#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;


void solve()
{
    string s;
    cin>>s;
    vector<int>cnt(27,0);
    n = s.size();
    for(int i=0;i<n;i++)
    {
        cnt[s[i]-'a']++;
    }

    int ans = n-1;
    for(int i=0;i<26;i++)
    {
        ans = min(ans,n-cnt[i]);
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
