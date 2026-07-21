Tags:Dilworth定理，插入计数，计数DP

Auther:Yzzz-F

题解：

一个合法序列一定可以拆解成最多不超过两个不降子序列

根据Dilworth 定理，最小链分解数=最长反链长度，因此，最长下降子序列的长度不超过2

我们考虑进行计数DP，按照从小到大插入的顺序进行插入计数

对于每次加入的数字，他一定是当前数字中最大的，那么只要他不插入到最后一位，就一定会形成下降子序列，

我们令dp(i,j)表示1-i全部插入，且所有长度为 2的下降子序列的左侧的数字中最右侧的位置为j，那么显然，i+1个数字不能插入到j的左边，否侧会形成长度为3 的下降子序列假设目前插入的所有数字的数目总和为sum ，那么我们可以从j+1-sum 的位置插入，或者插入到sum右侧

对此，我们要枚举sum右侧插入了多少元素，记为x ，则j+1到sum插入的元素的数目就是a[i+1]-x,插入到j+1到sum的位置的最左侧的元素会影响dp的第二维，因为插入的i+1会直接和本来在sum位置上的元素形成递减的子序列，也就是上述的  **所有长度为 2的下降子序列的左侧的数字中最右侧的位置为j**  ， 因此我们还要枚举插入到这一段 的元素的 最右侧的位置，

最终的状态转移方程为：

$$
dp(i+1,k)=\sum_{j.x}^{}  dp(i,j) * \binom{k-j-1}{a_i-x-1}
$$


代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=505,mod=998244353;
const int MOD=998244353;
long long fac[N],inv[N];
long long qpow(long long a,long long b,long long mod){
    long long ans=1;
    for(;b;b>>=1){
        if(b&1){
            ans=(1LL*ans*a)%mod;
        }
        a=(1LL*a*a)%mod;
    }
    return ans;
}
void init(int n){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(fac[i-1]*i)%MOD;
	inv[n]=qpow(fac[n],MOD-2,MOD);
	for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
long long c(int n,int m){
	if(n<m)return 0;
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1,0),sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(sum[n]+1));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum[i];j++){
            if(dp[i][j]){
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
                for(int k=j+1;k<sum[i+1];k++){
                    int l=max(0LL,a[i+1]-(k-j));
                    int r=min(a[i+1]-1,sum[i+1]-k-1);
                    for(int x=l;x<=r;x++){
                        dp[i+1][k]=(dp[i+1][k]+dp[i][j]*c(k-j-1,a[i+1]-x-1)%mod)%mod;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=sum[n];i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    init(501);
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}

```

