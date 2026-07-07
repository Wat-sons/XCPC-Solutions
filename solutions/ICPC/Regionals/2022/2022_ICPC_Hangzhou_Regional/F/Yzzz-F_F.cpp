#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	unordered_map<string ,int>mp;
	int n;
	cin>>n;
	string tar="bie";
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		bool ok=0;
		for(int j=1;j<=m;j++){
			string s;
			cin>>s;
			if(s.find(tar)!=s.npos){
				if(++mp[s]==1){
					cout<<s<<'\n';
					ok=1;
				}
				
			}
			
		}
		if(!ok)cout<<"Time to play Genshin Impact, Teacher Rice!\n";
	}
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
