Tags:二分，DP

Auther:Yzzz-F

题解：

依旧第k大，显然的二分；

我们二分当前第k大的线段长度为mid, 那么就意味着至少有k个线段的长度>=mid

对于这部分，我们用DP

我们设 $\(dp_{i,j}\)$ 是代表前 i 项，有 j 个大于等于 mid 且第 i 项是有连续的大于等于 k 个 1 的情况下所用的最少的更换的次数。

那么 $\(dp_{i,j} = \min(dp_{1,j-1},\ dp_{2,j-1},\ \dots) + (pre_i - pre_{i-mid})\)$。，左边 $\(\min\)$ 的右边的边界要根据 $\(i - mid\)$ 的位置是不是 1，如果是的话就接着一直找到最左边的 0。



代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    s=" "+s;
    vector<int>pre(n+1,0);
    vector<int>zero_pos(n+1,0);
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+(s[i]=='0');
        if(s[i]=='0')
            zero_pos[i]=i;
        else
            zero_pos[i]=zero_pos[i-1];
    }

    auto check=[&](int x)->bool{
        vector<vector<int>>dp(n+1,vector<int>(k+1,1e9));
        for(int i=0;i<=n;++i)dp[i][0]=0;

        for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j){
                dp[i][j]=dp[i-1][j];

                if(i<x)continue;

                int pos=i-x;
                int cnt=pre[i]-pre[pos];
                pos=zero_pos[pos];

                if(j==1){
                    dp[i][j]=min(dp[i][j],cnt);
                }else if(pos>0){
                    dp[i][j]=min(dp[i][j],dp[pos-1][j-1]+cnt);
                }
            }
        }
        return dp[n][k]<=m;
    };

    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```

