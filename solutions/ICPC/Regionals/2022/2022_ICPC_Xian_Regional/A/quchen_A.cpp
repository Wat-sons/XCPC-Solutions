#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e9;

int n,m,q;
const int B=200;

typedef pair<int,int> pii;

vector<pii> sw[N],que;
int key[N],cur[N],pos[N],tpos[N];
int a[B+5],b[B+5];
unordered_map<int,int> mp[B+5];

void solve()
{
    cin>>n>>m>>q;

    int block=(q+B-1)/B;

    for(int id=0;id<block;id++)
    {
        que.clear();

        for(int j=id*B;j<min(q,(id+1)*B);j++)
        {
            int op,x,y;
            cin>>op>>x;

            if(op==2)
            {
                x--;
                que.push_back({j,x});
            }
            else
            {
                cin>>y;
                x--;
                y--;
                sw[y].push_back({j,x});
            }
        }

        for(int i=0;i<n;i++)
        {
            key[i]=-1;
            cur[i]=i;
        }

        vector<int> v;
        int cnt=0;

        for(auto it:que)
        {
            int x=it.second;
            if(key[x]==-1)
            {
                key[x]=cnt++;
                v.push_back(x);
            }
        }

        for(int j=0;j<m;j++)
        {
            for(auto it:sw[j])
            {
                int x=cur[it.second];
                int y=cur[it.second+1];

                swap(cur[it.second],cur[it.second+1]);

                if(it.first/B!=id)continue;

                if(key[x]==-1)
                {
                    key[x]=cnt++;
                    v.push_back(x);
                }

                if(key[y]==-1)
                {
                    key[y]=cnt++;
                    v.push_back(y);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            cur[i]=i;
            pos[i]=i;
        }

        for(int i=0;i<cnt;i++)
        {
            tpos[i]=pos[v[i]];
        }

        int len=0;

        for(int j=0;j<m;j++)
        {
            for(auto it:sw[j])
            {
                int x=cur[it.second];
                int y=cur[it.second+1];

                if(it.first/B==id)
                {
                    for(int k=0;k<cnt;k++)
                    {
                        mp[len][tpos[k]]=pos[v[k]];
                    }

                    a[len]=it.first;
                    b[len]=it.second;
                    len++;
                }

                swap(cur[it.second],cur[it.second+1]);
                swap(pos[x],pos[y]);

                if(it.first/B==id)
                {
                    for(int k=0;k<cnt;k++)
                    {
                        tpos[k]=pos[v[k]];
                    }
                }
            }
        }

        for(int k=0;k<cnt;k++)
        {
            mp[len][tpos[k]]=pos[v[k]];
        }

        a[len]=inf;
        len++;

        for(auto it:que)
        {
            int T=it.first;
            int p=it.second;

            for(int j=0;j<len;j++)
            {
                p=mp[j][p];

                if(a[j]<T)
                {
                    if(b[j]==p)p=b[j]+1;
                    else if(b[j]==p-1)p=b[j];
                }
            }

            cout<<p+1<<'\n';
        }

        for(int j=0;j<len;j++)
        {
            mp[j].clear();
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
