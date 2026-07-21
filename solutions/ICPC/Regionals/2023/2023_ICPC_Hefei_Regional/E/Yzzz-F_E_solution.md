Tags:排序

Auther:Yzzz-F

题解：

显然x和y可以分开处理

对于同一种颜色的所有点，我们分别对x和y排序，对于每个点，累加上这个点减去前面的每个点的值，这个很容易遍历一遍就维护出来，或者用前缀和解决即可

最后所有答案乘2即可

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>numx(n*m+1),numy(n*m+1);
    vector<vector<int>>a(n+1,vector<int>(m+1));
    int num=0;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(!mp[a[i][j]]){
                mp[a[i][j]]=++num;
            }
            int col=mp[a[i][j]];
            numx[col].push_back(i);
            numy[col].push_back(j);
        }
    }
    int ans=0;
    for(int i=1;i<=num;i++){
        sort(numx[i].begin(),numx[i].end());
        int len=numx[i].size();
        int pre=0;
        for(int j=0;j<len;j++){
            ans+=(j)*numx[i][j]-pre;
            pre+=numx[i][j];
        }
        sort(numy[i].begin(),numy[i].end());
        len=numy[i].size();
        pre=0;
        for(int j=0;j<len;j++){
            ans+=(j)*numy[i][j]-pre;
            pre+=numy[i][j];
        }

    }
    ans*=2;
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

