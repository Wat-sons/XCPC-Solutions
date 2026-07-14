#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
ll  n,m;
ll k;
ll pre[N][N];
ll d[N][N];

void solve()
{

    ll mxx=0,mxy=0,mnx=0,mny=0;
    cin>>n>>m>>k;

    set<pair<ll,ll>>st;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            d[i][j]=0;
            pre[i][j]=0;
        }
    }
    string s;
    cin>>s;
    int sz = s.size();
    s = " "+s;
    ll dx = 0;
    ll dy = 0;
    for(int i=1;i<=sz;i++)
    {
        if(s[i]=='L')dy--;
        else if(s[i]=='R')dy++;
        else if(s[i]=='U')dx--;
        else dx++;
        st.insert({dx,dy});
        mxx = max(mxx,dx);
        mxy = max(mxy,dy);
        mnx = min(mnx,dx);
        mny = min(mny,dy);
    }
    ll ax1 = 1-mnx;
    ll ax2 = n-mxx;
    ll ay1 = 1-mny;
    ll ay2 = m-mxy;
    st.insert({0,0});

    for(auto [u,v]:st)
    {   
        ll x1 = ax1+u;
        ll x2 = ax2+u;
        ll y1 = ay1+v;
        ll y2 = ay2+v;
        x1 = max(1LL,x1);
        x2 = min(n,x2);
        y1 = max(1LL,y1);
        y2 = min(m,y2);
        if(x1>x2||y1>y2)continue;
        d[x1][y1]++;
        d[x2+1][y2+1]++;
        d[x1][y2+1]--;
        d[x2+1][y1]--;
    }



    ll rst = (ax2-ax1+1)*(ay2-ay1+1);
    if(ax1>ax2||ay1>ay2)rst=0;
    ll nd = rst-k;
    ll ans = 0;
    if(nd<0)
    {
        cout<<0<<'\n';
        return ;
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+d[i][j];
            if(pre[i][j]==nd)ans++;
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
