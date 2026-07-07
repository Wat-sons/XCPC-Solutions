#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const double INF = 1e15;
const double eps = 1e-9;
double x,p1,v1,p2,v2;

bool check(double t)
{

    double len1 = v1*t;
    double len2 = v2*t;

    if((x+p1)<=len1||(2*x-p1)<=len1)return true;

    if((x-p2+x)<=len2||(2*p2+x-p2)<=len2)return true;


    double l1,r1,l2,r2;
    if(len1>=p1&&len2>=x-p2)
    {
        l1=0;
        r1 = max({p1,len1-p1,p1+(len1-p1)/2});
        l2 = min({p2,x-(len2-x+p2),p2-(len2-(x-p2))/2});
        r2 = x;
        if(r1>=l2)return true;
    }

    if((x-p1)<=len1&&(p2<=len2))return true;



    return false;
}


void solve()
{   
    cin>>x>>p1>>v1>>p2>>v2;

    if(p1>p2)
    {
        swap(p1,p2);
        swap(v1,v2);

    }
    double ans = INF;
    double l = 0, r=INF;

    while(r-l>=eps)
    {
        double mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid-eps;
        }
        else 
        {
            l = mid+eps;
        }
    }
    
    printf("%.10lf\n",ans);
    
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
