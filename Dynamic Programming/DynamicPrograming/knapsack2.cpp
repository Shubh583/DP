#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<vector<ll>>dp;//(105,vector<ll>(100005,-1));
ll f(vector<int>&wet,vector<int>&val, int i, int tv){
   if(tv==0)return 0;
    if(i==wet.size())return INT_MAX;
    if(dp[i][tv]!=-1)return dp[i][tv];
    ll ans =INT_MAX;
    ans=min(ans,f(wet,val,i+1,tv));
    if(val[i]<=tv){
        ans=min(ans,wet[i]+f(wet,val,i+1,tv-val[i]));
    }
    return dp[i][tv]=ans;
}
 
 ll fbu(vector<int>&wet,vector<int>&val, int tv,int w){
  dp.resize(105,vector<ll>(100005,INT_MAX));
  for(int i=0;i<dp.size();i++){
    dp[i][0]=0;
  }
  int n=wet.size();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=tv;j++){
        ll ans =INT_MAX;
        ans=min(ans,dp[i+1][j]);
        if(val[i]<=j){
            ans=min(ans,wet[i]+dp[i+1][j-val[i]]);
        }
       dp[i][j]=ans;
        }
    }  int res=-1;
    for(int i=0;i<=n*1000;i++){
        if(dp[0][i]<=w)res=i;
    }
 return res;
 }
int main(){
int n, w;
cin>>n>>w;
vector<int>val(n);
vector<int>wet(n);
for(int i=0;i<n;i++){
    cin>>wet[i];
    cin>>val[i];
} int result=fbu(wet,val,n*1000,w);
// for(int i=0;i<=n*1000;i++){
//     if(f(wet,val,0,i)<=w)
//     result=i;
// }
cout<<result<<" ";
}