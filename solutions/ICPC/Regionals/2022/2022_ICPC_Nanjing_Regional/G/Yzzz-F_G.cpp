#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n;
    cin>>n;
    int S=1,cnt=1;
    int sum=0;
    stack<int> st;
    bool ok=1;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op == 0) st.push(i);
        if(op == 1){
            sum++;
            S++,cnt++;
        }else{
            sum--;
            cnt--;
        }
        while(sum < 0){
            if(st.empty()){
                ok=0;
                break;
            }
            st.pop();
            sum += 2;
            cnt += 2;
            S += 1;
        }
    }
    if(!ok){
        cout<<-1<<'\n';
        return ;
    }
    int g = gcd(S,cnt);
    cout << S/g << " " << cnt/g << "\n";
}
signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int T=1;
	cin>>T;
    while(T--) solve();
    return 0;
}
