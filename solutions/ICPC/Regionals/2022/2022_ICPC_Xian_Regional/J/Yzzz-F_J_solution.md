Tags:签到,排序

Auther:Yzzz-F

题解：

这道题显然，选择第i个元素后，任何长度为i的区间只能选择一个元素，因此最多选两个元素，所以不选，或者选择最大值的，或者最大+次大三种情况，取最大值即可

代码：



```c++
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    int ans=max(0LL,a[n]+a[n-1]);
    ans=max(ans,a[n]);
    cout<<ans<<'\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
}

```

