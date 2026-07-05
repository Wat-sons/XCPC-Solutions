#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,q;
string s[3];
int a[N],b[N];
set<int>st;
void solve()
{   
    cin>>n>>q;
    cin>>s[1];
    cin>>s[2];
    s[1] = " "+s[1];
    s[2] = " "+s[2];
    int pre = 0;
    for(int i=1;i<=n;i++)
    {
        int d1 = s[1][i]-'0';
        int d2 = s[2][i]-'0';
        a[i]=d1;
        b[i]=d2;
        if(d1+d2!=9)st.insert(i);

    }
    while(q--)
    {
        int r,c,d;
        cin>>r>>c>>d;

        
        auto it = st.upper_bound(c);
        int sum1 = 0;
        int sum2 = 0;
        int d1=0,d2=0;
        if(it!=st.end())
        {
            int idx = *it;
            d1 = a[idx];
            d2 = b[idx];
            sum1 = (d1+d2>=10)+a[c]+b[c];
        }
        else 
        {
            sum1 = a[c]+b[c];
        }

        if(r==1)
        {
            
            if(d==a[c])
            {
                cout<<sum1%10<<' '<<0<<'\n';
                continue;
            }
            sum2 = d+b[c]+((d1+d2)>=10);
            if(d+b[c]!=9)
            {
                st.insert(c);
            }
            else st.erase(c);
            a[c]=d;

        }
        else
        {
            if(d==b[c])
            {
                cout<<sum1%10<<' '<<0<<'\n';
                continue;
            }
            sum2 = d+a[c]+((d1+d2)>=10);
            if(d+a[c]!=9)
            {
                st.insert(c);
            }
            else 
            {
                st.erase(c);
            }
            b[c] = d;
            
        }


        cout<<sum2%10<<' ';
        ll res = 2;
        if((sum1>=10&&sum2<10)||(sum2>=10&&sum1<10))
        {
            auto it = st.lower_bound(c);
            if(it!=st.begin())
            {
                auto it2 = prev(it);
                res += (c-*it2);
            }
            else
            {
                res += c-1;
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
