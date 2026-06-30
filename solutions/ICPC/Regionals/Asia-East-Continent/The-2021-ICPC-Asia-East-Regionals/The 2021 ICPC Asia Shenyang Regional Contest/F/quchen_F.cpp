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
    string ans = "";
    for(int i=1;i<=n;i++)
    {
        set<char>st;
        map<char,int>mp;
        st.insert(s[i]);
        mp[s[i]]=0;
        for(int j=i-1;j>=1;j--)
        {
            if(st.count(s[j])==0)mp[s[j]] = st.size();
            st.insert(s[j]);
            
        }

        string cur="";
        for(int j=1;j<=i;j++)
        {
            cur+=mp[s[j]]+'a';
        }

        ans = max(ans,cur);
        
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
