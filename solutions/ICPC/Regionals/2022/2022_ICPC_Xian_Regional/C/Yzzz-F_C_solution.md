Tags:贪心,枚举

Auther:Yzzz-F

题解：

显然，先复制再造题一定优于先造题再复制，但是可能存在连续多轮造题的情况，因此我们只需要枚举复制的轮数，然后计算复制完后需要造几轮题 ，对所有结果取最小值即可



代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    int now=1;
    int ans=LLONG_MAX;
    for(int i=0;i<=32;i++){
        int timea=i*a;
        int timeb=(c+now-1)/now*b;
        int res=timea+timeb;
        ans=min(ans,res);
        now*=2;
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

