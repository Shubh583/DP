#define ll long long int
#include<bits/stdc++.h>
using namespace std;
vector<ll>arr(3005,0);
vector< vector<ll >> dp;
ll f(vector<ll>&arr, int i, int j){
    if(i==j)return arr[j];
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MIN;
   return dp[i][j]=max(arr[i]-f(arr,i+1,j),arr[j]-f(arr,i,j-1));
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    dp.resize(3005,vector<ll>(3005,-1));
    cout<<f(arr,0,n-1);
}