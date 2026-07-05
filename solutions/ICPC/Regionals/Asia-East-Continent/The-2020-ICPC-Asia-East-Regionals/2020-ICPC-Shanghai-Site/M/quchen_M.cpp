#include <bits/stdc++.h>
using namespace std;
const int N=3e2+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll n,m;
string s[N];
string s2[N];



void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }

    set<string>st;

    for(int i=1;i<=m;i++)
    {
        cin>>s2[i];
        string cur="";
        int sz = s2[i].size();
        for(int j=0;j<sz;j++)
        {
            if(s2[i][j]>='a'&&s2[i][j]<='z')cur+=s2[i][j];
            else 
            {
                cur+=s2[i][j];
                st.insert(cur);
            }
        }
        st.insert(s2[i]);
    }

    int ans = 0;

    set<string>st2;

    for(int i=1;i<=n;i++)
    {
        string cur="";
        int sz = s[i].size();
        bool ok = false;
        for(int j=0;j<sz;j++)
        {
            if(s[i][j]>='a'&&s[i][j]<='z')
            {
                cur+=s[i][j];
            }
            else 
            {
                cur+=s[i][j];
                if(st.count(cur))continue;
                else if(st2.count(cur))
                {
                    ok = true;
                    break;
                }
                else 
                {
                    ans++;
                    st2.insert(cur);
                    ok = true;
                    break;
                }
            }
        }   

        if(!ok)
        {
            ans++;
            st2.insert(s[i]);
        }
    }

    // for(auto v:st2)cout<<v<<'\n';
    // cout<<'\n';

    // for(auto v:st)cout<<v<<'\n';
    // cout<<'\n';

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
