#include <bits/stdc++.h>
using namespace std;
#define int long long

int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int g=exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return g;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1,0);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int x1=1,y1=0,x2=1,y2=0;
    int g1=exgcd(n,n*(n+1)/2,x1,y1);
    int g=exgcd(g1,m,x2,y2);
    sum%=m;
    int k=(m-sum+g-1)/g;
    int res=(k*g+sum)%m;
    cout<<res<<'\n';
    x1=(x1*x2%m*k%m+m)%m;
    y1=(y1*x2%m*k%m+m)%m;
    cout<<x1<<' '<<y1<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
