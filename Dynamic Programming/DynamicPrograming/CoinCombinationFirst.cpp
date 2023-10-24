#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;
 vector<int>  dp;
int f(vector<int>&nums, int x){
    if(x==0)return 1;
    //if(idx==nums.size())return 0;
    if(dp[x]!=-1)return dp[x];
    int result=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>x)break;
        result=(result%mod + (f(nums,x-nums[i])%mod))%mod; 
    }
      //if(result==INT_MAX)return dp[x]=INT_MAX;
     return dp[x]=result%mod;
}
int main(){
    dp.clear();
    dp.resize(1000006,-1);
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
   cout<< f(v,x);
    //if(ans==INT_MAX) cout<<-1 ; else cout<<ans;
}