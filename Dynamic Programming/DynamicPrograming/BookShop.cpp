#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int f(vector<int>&pr, vector<int>&pg,int i, int x){
    if(i==pr.size())return 0;
    if(x<0)return INT_MAX;
    if(dp[i][x]!=-1)return dp[i][x];
    int ans=INT_MIN;
    ans=f(pr,pg,i+1,x);
    if(x>=pr[i]){
        ans=max(ans,pg[i]+f(pr,pg,i+1,x-pr[i]));
    }
    return dp[i][x]= ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>pr(n);
    vector<int>pg(n);
    int x;
    cin>>x;
    dp.clear();
    dp.resize(1006,vector<int>(100007,-1));
    for(int i=0;i<n;i++){
        cin>>pr[i];}
        for(int i=0;i<n;i++){
        cin>>pg[i];
    }
    cout<<f(pr,pg,0,x);
}