Tags:贪心

Auther:Yzzz-F

题解：

函数f(x)可以看作x的三进制表示中位数以及各个位上数字的和

当l与r的位数相同的时候：

从高位到低位找到第一个二者不同的位，然后让r的这一位-1 后面的位全填2即可，同时要和原来的r对比一下因为r本身可能后面就全是2 

当r的位数比l多的时候：

假设第一个位置是1, 如果仍然按照上述操作， 这样会导致减少一个位数 反而减少了贡献为2

我们可以对每一位r比l多的位进行一次减一操作然后后续全部填满

为了统一逻辑我们甚至可以对两种情况都进行操作2 



代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int l,r;
    cin>>l>>r;
    auto f=[&](int x){
        int s=0;
        for(;x;x/=3)s+=x%3+1;
        return s;
    };
    int ans=f(r);
    vector<int>a;
    int t=r;
    while(t){
        a.push_back(t%3);
        t/=3;
    }
    reverse(a.begin(),a.end());
    int n=a.size();
    vector<int>p(n);
    p[n-1]=1;
    for(int i=n-2;i>=0;--i)p[i]=p[i+1]*3;
    int pre=0;
    for(int i=0;i<n;++i){
        int d=a[i];
        if(d>0){
            int v=pre*p[i]*3+(d-1)*p[i]+(p[i]-1);
            if(v>=l&&v<=r)ans=max(ans,f(v));
        }
        pre=pre*3+d;
    }
    cout<<ans<<'\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
}

```

