#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;

     vector<int>dp;
     int f(int target){
         if(target==0)return 1;
         if(dp[target]!=-1)return dp[target];
         int ans=0;
       for(int i=1;i<=6;i++){
           if(target-i < 0)continue;
           ans=(ans%mod+f(target-i)%mod)%mod;
       }
return dp[target]= ans%mod;
     }
    int main(){
     int n;
     cin>>n;
     dp.clear();
     dp.resize(1000006,-1);
     cout<<f(n);
    
    }