#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int H,W;
vector<vector<ll> > dp;
ll f( vector<vector<char> >&grid,int i, int j){
    if(i>H || j>W)return 0;
    if(i==H && j== W)return 1;
    if(grid[i][j]=='#')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans=0;
    ans+=f(grid,i,j+1)+f(grid,i+1,j);
    //ans+=;
    return dp[i][j]= ans%mod;
}
int main(){
    
    cin>>H>>W;
    dp.clear();
    dp.resize(1005,vector<ll>(1005, -1));
    vector<vector<char> > grid(H+1,vector<char>(W+1,0));
     for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>grid[i][j];
        }
     }
     
     cout<<(int)f(grid,1,1);
}