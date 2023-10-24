#define mod 100000007
#include<bits/stdc++.h>
using namespace std;
 vector< vector< int > > dp;
 int f(vector<int>&v,int idx, int target){
    if(target==0)return 1;
    if(idx>=v.size())return 0;
    if(dp[idx][target]!=-1)return dp[idx][target];
    int ans=0;
    for(int i=idx;i<v.size();i++){
        if(v[i]>target)break;
        ans=(ans%mod + f(v,i, target-v[i])%mod)%mod;
    }
 return dp[idx][target]= ans%mod; //dp[idx][target]=ans;
 }
int main(){
    dp.clear();
    dp.resize(105,vector<int>(1000007,-1));
    int n; int x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
     sort(v.begin(),v.end());
    cout<< f(v,0,x);
}