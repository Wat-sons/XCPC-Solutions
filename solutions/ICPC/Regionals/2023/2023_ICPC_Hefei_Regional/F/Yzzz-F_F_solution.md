Tags:签到

Auther:Yzzz-F

题解：

统计每种颜色出现的次数即可



代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    map<string ,int >mp;
    for(int i=1;i<=n;i++){
        string  s;
        cin>>s;
        mp[s]++;
    }
    string ans="uh-oh";
    for(auto [x,cnt]:mp){
        if(cnt*2>n){
            ans=x;
            break;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}

```

