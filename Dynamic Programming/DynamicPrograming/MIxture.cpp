#include<bits/stdc++.h>
using namespace std;
vector<vector<int > >dp;
int g(vector<int>&clr,int i, int j){
    int res=0;
    for(int h=i;h<=j;h++)
    res=(res%100 + clr[h]%100 )%100;
    return res;
    }
int f(vector<int>&clr,int i, int j){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
     int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
  ans=min(ans,f(clr,i,k)+f(clr,k+1,j)+g(clr,i,k)*g(clr,k+1,j));
    } return dp[i][j]= ans;
}
int main(){
    int n;
   
    while(cin>>n){
     dp.clear();
    dp.resize(104,vector<int>(104,-1));
    vector<int>clr;
    for(int i=0;i<n;i++){
        int r; cin>>r;
        clr.push_back(r);
    }
    cout<<f(clr,0,clr.size()-1)<<endl;
    clr.clear();
    }
}