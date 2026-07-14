#include <bits/stdc++.h>
using namespace std;
const int N=7;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n,m;

ll a[N],b[N];
ll aatk[N],batk[N];
ll cnt = 0;
double ans1=0.0,ans2=0.0,ans3=0.0;
set<int>sta,stb;

void dfs(bool ok,set<int> &sta,set<int> &stb,double p)
{
    if(sta.empty()&&!stb.empty())
    {
        ans2+=p;
        return ;
    }
    else if(sta.empty()&&stb.empty())
    {
        ans3+=p;
        return;
    }
    else if(!sta.empty()&&stb.empty())
    {
        ans1+=p;
        return ;
    }

    if(ok==1)
    {
        int idx = *sta.begin();
        double np = p/double(stb.size());

        vector<int> nstb;
        for(auto v:stb)nstb.push_back(v);

        for(auto v:nstb)
        {   
            int idx2 = v%m;

            ll oa = a[idx%n];
            ll ob = b[idx2%m];

            sta.erase(idx);
            stb.erase(v);

            b[idx2%m]-=aatk[idx%n];
            a[idx%n]-=batk[idx2%m];

            if(a[idx%n]>0)
            {
                sta.insert(idx+n);
            }

            if(b[idx2%m]>0)
            {
                stb.insert(v);
            }   

            dfs(0,sta,stb,np);

            a[idx%n]=oa;
            b[idx2%m]=ob; 

            sta.erase(idx+n);
            sta.insert(idx);

            stb.erase(v);
            stb.insert(v);
        }
    }
    else 
    {
        int idx2 = *stb.begin();
        double np = p/double(sta.size());

        vector<int> nsta;
        for(auto v:sta)nsta.push_back(v);

        for(auto v:nsta)
        {   
            int idx = v%n;

            ll oa = a[idx%n];        
            ll ob = b[idx2%m];

            sta.erase(v);
            stb.erase(idx2);

            a[idx%n]-=batk[idx2%m];
            b[idx2%m]-=aatk[idx%n];

            if(a[idx%n]>0)
            {
                sta.insert(v);
            }

            if(b[idx2%m]>0)
            {
                stb.insert(idx2+m);
            }   

            dfs(1,sta,stb,np);

            a[idx%n]=oa;
            b[idx2%m]=ob; 

            stb.erase(idx2+m);
            stb.insert(idx2);

            sta.erase(v);
            sta.insert(v);
        }
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        aatk[i] = a[i];
        sta.insert(i);
    }

    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        batk[i] = b[i];
        stb.insert(i);
    }

    if(n>m)
    {
        dfs(1,sta,stb,1.0);
    }
    else if(n<m)
    {
        dfs(0,sta,stb,1.0);
    }
    else 
    {
        dfs(0,sta,stb,0.5);
        dfs(1,sta,stb,0.5);
    }

    printf("%.12lf\n",ans1);
    printf("%.12lf\n",ans2);
    printf("%.12lf\n",ans3);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
