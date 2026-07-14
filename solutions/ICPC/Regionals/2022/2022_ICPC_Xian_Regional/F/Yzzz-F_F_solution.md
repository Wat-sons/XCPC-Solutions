Tags:签到

Auther:Yzzz-F

题解：

对于不同的情况简单分类讨论即可



代码：

```c++
    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    void solve() {
        int n,c1,c2;
        cin>>n>>c1>>c2;
        c1=min(c1,c2);
        if(c1*2<=c2){
            cout<<n*3LL*c1<<'\n';
            return  ;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            int num1=0,num2=0;
            if(s[0]==s[1]||s[1]==s[2]||s[2]==s[0]){
                ans+=min(c1+c2,3*c1);
            }else ans+=min(3*c1,3*c2);
        }
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

