#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    string s;
    cin>>s;
    int n=s.size();
    string s2="edgnb";
    int ans=0;
    for(int i=0;i<n;i++){
        bool ok=1;
        for(int j=0;j<5;j++){
            if(s[i+j]!=s2[j]){
                ok=0;
                break;
            }
        }
        ans+=ok;
    }
    cout<<ans<<'\n';
    return 0;
}
