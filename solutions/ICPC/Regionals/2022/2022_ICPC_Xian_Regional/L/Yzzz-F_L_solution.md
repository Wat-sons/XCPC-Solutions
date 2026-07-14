Tags:贪心

Auther:Yzzz-F

题解：

显然，两种条件，要么成为一条链，要么成为一条反链，如果选择一条链，那么链的数目应该等于当前的叶子节点的数目，如果选择用反链，用在叶子节点上最优，若不在叶子节点上，无法减少链的个数

因此，我们枚举反链的层数，然后剩下的新的叶子节点的数目就是链的个数，对所有的结果和取最小值即可



代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    vector<int>fa(n+1,0);
    vector<int>deg(n+1,0);
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        deg[fa[i]]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0)q.push(i);
    }
    int ans=INT_MAX;
    int num1=0;
    ans=min(ans,(long long)q.size());
    while(q.size()){
        int num=q.size();
        ans=min(ans,num1+num);
        num1++;
        while(num){
            auto u=q.front();q.pop();
            if(--deg[fa[u]]==0){
                q.push(fa[u]);
            }
            num--;
        }
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

