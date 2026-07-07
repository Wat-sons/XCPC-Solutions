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
    cin>>n;
    set<string>st;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        
        bool ok = false;
        for(int j=1;j<=m;j++)
        {
            string s;
            cin>>s;
            int sz = s.size();
            
            if(st.count(s))continue;
            
            for(int k=0;k<sz;k++)
            {
                if(k+2<sz&&s[k]=='b'&&s[k+1]=='i'&&s[k+2]=='e')
                {
                    st.insert(s);
                    cout<<s<<'\n';
                    ok = true;
                    break;
                }
            }
        }
        if(!ok)cout<<"Time to play Genshin Impact, Teacher Rice!\n";

    }
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
