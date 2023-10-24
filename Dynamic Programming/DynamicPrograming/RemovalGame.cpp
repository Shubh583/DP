#include<bits/stdc++.h>
using namespace std;
vector < vector <int> >dp;
 int f(vector<int>&v, int i, int e){
    //if(i==v.size()-2)return max(v[i],v[i+1]);
   if(i==e)return v[i];
    if(i==e-1)return v[i];
   // if(i>=v.size())return 0;
    if(dp[i][e]!=-1)return dp[i][e];
    int ans=INT_MIN;
    ans=max(max(v[i]+f(v,i+2,e),0+f(v,i+1,e)), max(v[e]+f(v,i,e-2),0+f(v,i,e-1)));
    return dp[i][e]= ans;
 }
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(5004,vector<int>(5004,-1));
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<max(f(v,0,n-2),f(v,1,n-1));
}