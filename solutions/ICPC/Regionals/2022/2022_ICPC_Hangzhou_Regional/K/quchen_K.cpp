#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,q;
string s[501010];
ll dp[28][28];
ll pass[N];
ll cnt = 0;
ll tree[N][27];
ll ed[N];
ll dx = 0;
void insert(string s)
{
    int cur = 0;         
    // pass[cur]++;          

    for (int i=0;i<s.size();i++)
    {
        int idx = s[i]-'a';
        for(int j=0;j<26;j++)
        {
            if(j==idx)continue;
            if(tree[cur][j])
            {
                dp[j][idx]+=pass[tree[cur][j]];
            }
        }
        if(tree[cur][idx]==0)
        {
            tree[cur][idx]=++cnt;
        }
        cur = tree[cur][idx];
        pass[cur]++;
    }

    ed[cur]++;
    dx+=pass[cur]-ed[cur];
    


}


void solve()
{
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
    {   
        cin>>s[i];
        insert(s[i]);
    }

    while(q--)
    {
        string s;
        cin>>s;

        ll res =dx ;
        
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int idx1 = s[i]-'a';
                int idx2 = s[j]-'a';
                res+=dp[idx2][idx1];
            }
        }
        cout<<res<<'\n';
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
