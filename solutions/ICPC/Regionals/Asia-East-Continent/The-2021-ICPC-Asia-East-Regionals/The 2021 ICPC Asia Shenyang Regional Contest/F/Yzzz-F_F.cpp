#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
string s;
string getpre(int n){
    vector<int>sufpos(30,0),sufnum(n+29,0);
    unordered_map<char,int>mp;
    int nums=0;
    for(int i=1;i<=n;i++){
        sufpos[s[i]-'a']=i;
    }
    for(int i=n;i>=1;i--){
        sufnum[i]=sufnum[i+1];
        if(mp[s[i]]){
            continue;
        }else {
            nums++;
            mp[s[i]]=1;
            sufnum[i]=nums;
        }
    }
    string ans="";
    for(int i=1;i<=n;i++){
        int c=s[i]-'a';
        ans+='a'+sufnum[sufpos[c]+1];
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    cin>>s;
    s=" "+s;
    string str="";
    for(int i=1;i<=n;i++){
        string  res=getpre(i);
        if(res>str){
            str=res;
        }
    }
    cout<<str<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
}
