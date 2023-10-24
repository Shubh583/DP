#include<bits/stdc++.h>
using namespace std;
 vector<int>  dp;
int f(vector<int>&nums, int x){
    if(x==0)return 0;
    //if(idx==nums.size())return 0;
    if(dp[x]!=-2)return dp[x];
    int result=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>x)continue;
        result=min(result,f(nums,x-nums[i])); 
    }
      if(result==INT_MAX)return dp[x]=INT_MAX;
     return dp[x]=1+result;
}
int main(){
    dp.clear();
    dp.resize(1000006,-2);
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans= f(v,x);
    if(ans==INT_MAX) cout<<-1 ; else cout<<ans;
}