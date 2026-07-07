#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;

struct Node
{
    char c;
    int t;
    int v;
    int x,y;
    int mn,mx;
}b[1001][15];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        ll sumt,sumv;
        cin>>sumt>>sumv;
        ll csumv = 0,csumt = 0;
        ll mxt=0;
        ll mnt=0;
        vector<int>v;
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            b[i][j].c = c;
            if(c=='.')continue;
            else if(c=='-')
            {
                cin>>b[i][j].t;
                
            }
            else if(c=='+')
            {
                cin>>b[i][j].t>>c>>b[i][j].v;
                csumt++;
                csumv+=b[i][j].v+20*(b[i][j].t-1);
            }
            else 
            {
                cin>>b[i][j].x>>b[i][j].y;
                b[i][j].mn = (b[i][j].y-b[i][j].x)*20+240;
                b[i][j].mx = (b[i][j].y-1)*20+299;
                v.push_back(j);
            }
        }    
        
        int r = sumt-csumt;
        int rs = sumv-csumv;
        int sz = v.size();
        if(r<0||r>sz)
        {
            cout<<"No\n";
        }
        else 
        {
            bool ok = false;
            for(int j=0;j<(1<<sz);j++)
            {
                int cnt = 0;
                ll mn = 0;
                ll mx = 0;
                ll cntt = 0;
                for(int kk=0;kk<sz;kk++)
                {
                    if((j>>kk)&1)
                    {
                        cnt++;
                        mn += b[i][v[kk]].mn;
                        mx += b[i][v[kk]].mx;
                        cntt+=b[i][v[kk]].x-1;
                    }
                }
                if(cnt!=r)continue;
                if(mn>rs||mx<rs)continue;
                cout<<"Yes\n";
                ll r2 = rs-mn;
                int nd = r2/20;

                if(nd>=cntt)
                {
                    ll nd2 = r2-cntt*20;
                    for(int kk=0;kk<sz;kk++)
                    {
                        if((j>>kk)&1)
                        {
                            b[i][v[kk]].t = b[i][v[kk]].y;
                            if(nd2>=60)
                            {
                                b[i][v[kk]].v = 299;
                                nd2 -= 59;
                            }
                            else 
                            {
                                b[i][v[kk]].v = 240+nd2;
                                nd2 = 0;
                            }
                            b[i][v[kk]].c = '+';
                        }
                        else 
                        {
                            b[i][v[kk]].c = '-';
                            b[i][v[kk]].t = b[i][v[kk]].y;
                        }
                    }
                }
                else 
                {
                    int nd2 = r2%20;
                    for(int kk=0;kk<sz;kk++)
                    {
                        if((j>>kk)&1)
                        {
                            if(b[i][v[kk]].x-1<=nd)
                            {
                                b[i][v[kk]].t = b[i][v[kk]].y;
                                nd -= b[i][v[kk]].x-1;
                            }
                            else
                            {
                                b[i][v[kk]].t = b[i][v[kk]].y-b[i][v[kk]].x+nd+1;
                                nd = 0;
                            }
                            if(nd2>=60)
                            {
                                b[i][v[kk]].v = 299;
                                nd2 -= 59;
                            }
                            else 
                            {
                                b[i][v[kk]].v = 240+nd2;
                                nd2 = 0;
                            }
                            b[i][v[kk]].c = '+';
                        }
                        else 
                        {
                            b[i][v[kk]].c = '-';
                            b[i][v[kk]].t = b[i][v[kk]].y;
                        }
                    }
                }


                for(int j=1;j<=m;j++)
                {
                    cout<<b[i][j].c<<' ';
                    if(b[i][j].c=='.')cout<<'\n';
                    else if(b[i][j].c=='-')cout<<b[i][j].t<<'\n';
                    else if(b[i][j].c=='+')cout<<b[i][j].t<<"/"<<b[i][j].v<<'\n';
                }
            
                
                ok = true;

                break;

            }


            if(!ok)
            {
                cout<<"No\n";
            }
        }

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
