#include <bits/stdc++.h>
using namespace std;
const int N=3e6+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e18;
int n;
int a[N];
ll b[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        
    }

    ll cnt = 0;
    ll sum = 1;
    ll num = 1;
    vector<int>vec;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            sum++;
            num++;
        }
        else if(a[i]==-1)
        {
            num--;
        }
        else 
        {
            num++;
            sum++;
            cnt++;
        }
        b[i] = num;
        if(num<=0)
        {
            cout<<-1<<'\n';
            return ;
        }

        ll cur = (num-1)/2;
        if(cnt>cur)
        {
            cnt = cur;
        }

    }
    sum -= cnt;
    num -= 2*cnt;
    ll g = gcd(sum,num);
    num/=g;
    sum/=g;
    cout<<sum<<' '<<num<<'\n';

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
