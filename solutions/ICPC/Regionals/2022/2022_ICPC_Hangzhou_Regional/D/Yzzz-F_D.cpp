#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
  //注释部分为打表
	// int n;
	// cin>>n;
	// vector<double>a(n+1,0);
	// for(int i=1;i<=n;i++){
	// 	cin>>a[i];
	// }
	// for(int j=1;j<=1000;j++){

	// 	for(int i=1;i<=n;i++){
	// 		int pos=i+1;
	// 		if(pos>n)pos%=n;
	// 		a[pos]+=a[i]/2;
	// 		a[i]/=2;
	// 	}
	// 	for(int i=1;i<=n;i++){
	// 		cout<<a[i]<<' ';
	// 	}
	// 	cout<<'\n';
	// }
	int n;
	cin>>n;
	double sum=0;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		sum+=num;
	}
	double nums=sum;
	nums/=(n+1);
	cout<<fixed<<setprecision(10);
	for(int i=1;i<=n;i++){
		if(i==1){
			cout<<nums*2<<' ';
		}else cout<<nums<<' ';
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
/*
1:



*/
