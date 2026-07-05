#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e5+5;

int a[N];
bool vis[N];
int dis[10]={1,11,111,1111,10,110,1110,100,1100,1000};

int add(int u,int d){
    int res=0,base=1;
    for(int i=0;i<4;i++){
        int bu=u%10;
        int bd=d%10;
        res+=((bu+bd)%10+10)%10*base;
        u/=10;
        d/=10;
        base*=10;
    }
    return res;
}

void solve(){
        int x,y;
        cin>>x>>y;
        int df=0,base=1;
        int tx=x,ty=y;
        for(int i=0;i<4;i++){
            int dx=tx%10,dy=ty%10;
            df+=((dy-dx+10)%10)*base;
            base*=10;
            tx/=10;ty/=10;
        }
        cout<<a[df]<<'\n';
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(a,0x3f,sizeof a);
    a[0]=0;
    vis[0]=1;
    queue<int>q;
    q.push(0);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<10;i++){
            int v1=add(u,dis[i]);
            if(!vis[v1]){
                vis[v1]=1;
                a[v1]=a[u]+1;
                q.push(v1);
            }
            int v2=add(u,-dis[i]);
            if(!vis[v2]){
                vis[v2]=1;
                a[v2]=a[u]+1;
                q.push(v2);
            }
        }
    }
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
