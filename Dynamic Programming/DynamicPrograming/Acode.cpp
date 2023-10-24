#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>dp;
ll f(string& s, int i){
    if(i<0)return 1;
    if(dp[i]!=-1)return dp[i];
    ll ans=0;
    if(s[i]-'0'>0)ans+=f(s, i-1);
    if(s[i-1]-'0'>0 && (s[i-1]-'0')*10+(s[i]-'0')<=26)  {
        ans+=f(s,i-2);
    }
    return dp[i] = ans;
}
int main(){
    string s;
    dp.clear();
    dp.resize(5005,-1);
    cin>>s;
    cout<<f(s,s.size()-1);
}