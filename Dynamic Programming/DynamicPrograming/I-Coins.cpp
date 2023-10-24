#include<bits/stdc++.h>
using namespace std;
double dp[3005][3005];
double f(vector<double>&c,int i, int x){
   if(x==0)return 1;
  if(i==-1)return 0;
 
  if(dp[i][x]>-0.9)return dp[i][x];
  return dp[i][x]=f(c,i-1,x-1)*c[i]+f(c,i-1,x)*(1-c[i]);
}
int main(){
  int n;
  cin>>n;
 
  vector<double>c(n);
  for(int i=0;i<n;i++){
    cin>>c[i];
  } memset(dp,-1,sizeof dp);
  cout<<fixed<<setprecision(9)<<f(c,n-1,(n+1)/2)<<endl;
}
