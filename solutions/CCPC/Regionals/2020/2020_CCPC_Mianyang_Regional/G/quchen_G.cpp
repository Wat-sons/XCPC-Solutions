#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = -4e18;


int n,m;
int a[5];

bool check()
{
	if(a[1]==0&&a[2]==0)
	{
		if(a[3]==0)
		{
			if(a[0]%2==1||a[0]==0)return false;
			else return true;
		}
		else 
		{
			return a[0]%2;
		}
	}
	
	if(a[0]%2==0)
	{
		if(a[1]%3==0)return false;
		else if(a[1]%3==1&&a[2]==0)return false;
		
	}
	else 
	{
		if(a[1]%3==1&&a[2]!=0)return false;
		else if(a[1]%3==2&&a[2]<=1)return false;
	}
	return true;

}

void solve()
{
	for(int i=0;i<=3;i++)
	{
		cin>>a[i];
	}
	
	if(check())cout<<"Rabbit\n";
	else cout<<"Horse\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cout<<"Case #"<<i<<": ";
        solve();
		
    }
    return 0;
}


