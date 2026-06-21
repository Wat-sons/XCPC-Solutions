#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
ll dx,dy;

int dir[4][2] = {0,1,0,-1,-1,0,1,0};

void solve()
{
    cin>>dx>>dy;
    vector<int>cnt(4,0);
    vector<vector<int>>v2(4);
    string s;
    cin>>s;
    n = s.size();
    s = " "+s;

    ll edx=0,edy=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='U')
        {
            edy++;
            cnt[0]++;
            v2[0].push_back(i);
        }
        else if(s[i]=='D')
        {
            edy--;
            cnt[1]++;
            v2[1].push_back(i);
        }
        else if(s[i]=='L')
        {
            edx--;
            cnt[2]++;
            v2[2].push_back(i);
        }
        else 
        {
            edx++;
            cnt[3]++;
            v2[3].push_back(i);
        }
    }

    if(edx==dx&&edy==dy)
    {
        cout<<"Impossible\n";
    }
    else if(dx==0&&dy==0) 
    {
        cout<<"Impossible\n";
    }
    else if(dx == 0 && cnt[2] == 0 && cnt[3] == 0)
    {
        if((dy > 0 && edy >= dy) || (dy < 0 && edy <= dy))
        {
            cout << "Impossible\n";
        }
        else
        {
            if(dy > 0)
            {
                // 地雷在上方，先往下走
                for(int i = 1; i <= cnt[1]; i++) cout << "D";
                for(int i = 1; i <= cnt[0]; i++) cout << "U";
            }
            else
            {
                // 地雷在下方，先往上走
                for(int i = 1; i <= cnt[0]; i++) cout << "U";
                for(int i = 1; i <= cnt[1]; i++) cout << "D";
            }
            cout << '\n';
        }
    }
    else if(dy == 0 && cnt[0] == 0 && cnt[1] == 0)
    {
        if((dx > 0 && edx >= dx) || (dx < 0 && edx <= dx))
        {
            cout << "Impossible\n";
        }
        else
        {
            if(dx > 0)
            {
                // 地雷在右边，先往左走
                for(int i = 1; i <= cnt[2]; i++) cout << "L";
                for(int i = 1; i <= cnt[3]; i++) cout << "R";
            }
            else if(dx < 0)
            {
                // 地雷在左边，先往右走
                for(int i = 1; i <= cnt[3]; i++) cout << "R";
                for(int i = 1; i <= cnt[2]; i++) cout << "L";
            }
            else
            {
                // 地雷是原点，终点不是原点，走最终方向优先
                if(edx > 0)
                {
                    for(int i = 1; i <= cnt[3]; i++) cout << "R";
                    for(int i = 1; i <= cnt[2]; i++) cout << "L";
                }
                else
                {
                    for(int i = 1; i <= cnt[2]; i++) cout << "L";
                    for(int i = 1; i <= cnt[3]; i++) cout << "R";
                }
            }
            cout << '\n';
        }
    }
    else
    {

        ll cx = 0;
        ll cy = 0;
        if(dx==0)
        {
            if(cnt[2])
            {
                cout<<"L";
                cx--;
                cnt[2]--;
            }
            else
            {
                cout<<"R";
                cx++;
                cnt[3]--;
            }
        }
        
        if(dy==0)
        {
            if(cnt[0])
            {
                cout<<"U";
                cy++;
                cnt[0]--;
            }
            else
            {
                cy--;
                cout<<"D";
                cnt[1]--;
            }
        }

        // cout<<cnt[2]<<' '<<cnt[3]<<'\n';
        
        for(int i=1;i<=min(cnt[0],cnt[1]);i++)
        {
            cout<<"UD";
        }

        ll v1 = min(cnt[0],cnt[1]);
        cnt[0] -= v1;
        cnt[1] -=v1;


        for(int i=1;i<=min(cnt[2],cnt[3]);i++)
        {
            cout<<"LR";
        }

        ll v2 = min(cnt[2],cnt[3]);
        cnt[2] -= v2;
        cnt[3] -= v2;

        ll mnx=cx,mny=cy,mxx=cx,mxy=cy;

        if(cnt[0]&&cnt[2])
        {
            mxy = cy+cnt[0];
            mnx = cx-cnt[2];
            mny = cy;
            mxx = cx;

            if(dx==mnx)
            {
                for(int i=1;i<=cnt[0];i++)
                {
                    cout<<"U";
                }
                for(int i=1;i<=cnt[2];i++)
                {
                    cout<<"L";
                }
            }
            else 
            {
                for(int i=1;i<=cnt[2];i++)
                {
                    cout<<"L";
                }
                for(int i=1;i<=cnt[0];i++)
                {
                    cout<<"U";
                }
            }
        }
        else if(cnt[1]&&cnt[2])
        {
            mny = cy-cnt[1];
            mnx = cx-cnt[2];
            mxy = cy;
            mxx = cx;

            if(dx==mnx)
            {
                for(int i=1;i<=cnt[1];i++)
                {
                    cout<<"D";
                }
                for(int i=1;i<=cnt[2];i++)
                {
                    cout<<"L";
                }
            }
            else 
            {
                for(int i=1;i<=cnt[2];i++)
                {
                    cout<<"L";
                }
                for(int i=1;i<=cnt[1];i++)
                {
                    cout<<"D";
                }
            }
        }
        else if(cnt[0]&&cnt[3])
        {
            mxy = cy+cnt[0];
            mxx = cx+cnt[3];
            mny = cy;
            mnx = cx;

            if(dx==mxx)
            {
                for(int i=1;i<=cnt[0];i++)
                {
                    cout<<"U";
                }
                for(int i=1;i<=cnt[3];i++)
                {
                    cout<<"R";
                }
            }
            else 
            {
                for(int i=1;i<=cnt[3];i++)
                {
                    cout<<"R";
                }
                for(int i=1;i<=cnt[0];i++)
                {
                    cout<<"U";
                }
            }
        }
        else if(cnt[1]&&cnt[3]) 
        {
            mny = cy-cnt[1];
            mxx = cx+cnt[3];
            mxy = cy;
            mnx = cx;

            if(dx==mxx)
            {
                for(int i=1;i<=cnt[1];i++)
                {
                    cout<<"D";
                }
                for(int i=1;i<=cnt[3];i++)
                {
                    cout<<"R";
                }
            }
            else 
            {
                for(int i=1;i<=cnt[3];i++)
                {
                    cout<<"R";
                }
                for(int i=1;i<=cnt[1];i++)
                {
                    cout<<"D";
                }
            }
        }
        else 
        {
            for(int i=0;i<=3;i++)
            {
                for(int j=0;j<cnt[i];j++)
                {
                    if(i==0)cout<<"U";
                    else if(i==1)cout<<"D";
                    else if(i==2)cout<<"L";
                    else cout<<"R";
                }
            }
        }




        cout<<'\n';
    }

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
