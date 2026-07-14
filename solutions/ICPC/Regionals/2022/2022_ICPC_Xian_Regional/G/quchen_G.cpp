#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll cnt = 0;
string s[N];

bool cmp(string a,string b)
{
    return a.size()<b.size();
}

void solve()
{   
    cin>>n;
    set<string>st;
    for(int i=1;i<=n;i++)
    {   
        cin>>s[i];
    }
    sort(s+1,s+1+n,cmp);
    ll res = 0;
    for(int i=1;i<=n;i++)
    {
        ll sz = s[i].size();
        if(sz==1|| (st.count(s[i].substr(0,sz-1)) && st.count(s[i].substr(1))) )
        {
            st.insert(s[i]);
            res = max(res,sz);
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
