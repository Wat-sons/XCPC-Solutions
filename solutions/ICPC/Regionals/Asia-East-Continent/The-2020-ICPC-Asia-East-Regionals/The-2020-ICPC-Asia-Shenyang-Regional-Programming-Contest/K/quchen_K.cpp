#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;

struct Node
{
    bool v;
    ll p;
}a[N];


ll cnt1,cnt0=0;

bool cmp(Node a,Node b)
{
    return a.p<b.p;
}

struct Node2
{
    ll tp,fp,fn,tn;
    double fpr,tpr;

}b[N];

bool cmp2(Node2 a,Node2 b)
{
    if(a.fp*(b.tn+b.fp)!=b.fp*(a.tn+a.fp))
    {
        return a.fp*(b.tn+b.fp)<b.fp*(a.tn+a.fp);
    }
    else return a.tp*(b.tp+b.fn)>b.tp*(a.tp+a.fn);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c>>a[i].p;
        if(c=='-')
        {
            cnt0++;
            a[i].v=false;
        }
        else 
        {
            cnt1++;
            a[i].v=true;
        }
    }

    sort(a+1,a+1+n,cmp);

    ll ccnt0=0;
    ll ccnt1=0;

    int idx = 0;

    for(int i=1;i<=n;i++)
    {
        ll fp=0,tp=0,fn=0,tn=0;
        while(i<=n&&a[i].p==a[i+1].p)
        {
            
            if(!a[i].v)ccnt0++;
            else ccnt1++;
            i++;

            // cout<<ccnt1<<' '<<ccnt0<<'\n';
        }
        
        if(!a[i].v)ccnt0++;
        else ccnt1++;

        tp = cnt1 - ccnt1;
        fn = ccnt1;
        tn = ccnt0;
        fp = cnt0 - ccnt0;

        // cout<<i<<' '<<fp<<' '<<tp<<'\n';
        idx++;
        b[idx].tp=tp;
        b[idx].tn=tn;
        b[idx].fn=fn;
        b[idx].fp=fp;
        if(tp==0)b[idx].tpr=0;
        else b[idx].tpr = tp*1.0/(tp+fn);
        if(fp==0)b[idx].fpr =0;
        else b[idx].fpr = fp*1.0/(tn+fp);
    }

    sort(b+1,b+1+idx,cmp2);
    double ans = 0;
    double mx = 0.0;
    for(int i=1;i<=idx;i++)
    {
        
        // printf("%.10lf,%.10lf\n",b[i].tpr,b[i].fpr);
        mx = max(mx,b[i].tpr);
        if(i!=idx)ans += (b[i+1].fpr-b[i].fpr)*mx;
        else ans+=(1-b[i].fpr)*mx;
    }

    printf("%.10lf\n",ans);

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
