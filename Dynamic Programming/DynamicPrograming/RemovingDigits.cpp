#include<bits/stdc++.h>
using namespace std;
vector<int> get(int n){
    vector<int>r;
    while(n>0){
        r.push_back(n%10);
        n/=10;
    }
      reverse(r.begin(),r.end());
      return r;
}
vector<int>dp;
int f(int n){
    if(n==0)return INT_MAX;
    if(n<=9)return 1;
    if(dp[n]!=-1)return dp[n];
    vector<int>helper=get(n);
    int result= INT_MAX;
    for(int i=0;i<helper.size();i++){
        if(helper[i]==0)continue;
        result=min(result,f(n-helper[i]));//cout<<result<<" ";
    }
     return dp[n]=1+result;
}
int main(){
   
int n;
cin>>n;
  dp.clear();
    dp.resize(1000005,-1);
cout<<f(n);

}