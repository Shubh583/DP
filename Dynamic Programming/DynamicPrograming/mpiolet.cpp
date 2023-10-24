#include<bits/stdc++.h>
using namespace std;
 vector< vector<int> >dp;
 int f(vector<int>&c,vector<int>&a, int i, int x){
if(i==a.size())return 0;
    if(dp[i][x]!=-1)return dp[i][x];
    if(x==0){
      return dp[i][x]= f(c,a,i+1,x+1)+a[i];
    }
    else if(x==a.size()-i){
     return  dp[i][x]=  f(c,a,i+1,x-1)+c[i];
    }
    else {
 return dp[i][x]=  min(f(c,a,i+1,x+1)+a[i], f(c,a,i+1, x-1)+c[i]);

    }
 }
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+4, vector<int>(n+4,-1));
    vector<int>c(n);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        cin>>a[i];
    } 
     int x=0;
   cout<< f(c,a,0,x);
}