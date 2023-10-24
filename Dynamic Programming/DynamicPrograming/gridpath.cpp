#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;
 vector<vector<int> >dp;
 bool cango(vector< vector< char> > &v, int i, int j){
    return (v[i][j]=='.'); cout<<" ram "<<endl;
 }
int f(vector< vector< char> > &v, int i, int j){
   // if(v[i][j]=='*')return 0;
    if(i==v.size()-1&& j== v.size()-1) return 1;
    if(i>=v.size() || j>=v.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
   if(cango(v,i,j)) {ans= (ans%mod + f(v,i+1,j)%mod)%mod;}
 if(cango(v,i,j)) {ans= (ans%mod + f(v,i,j+1)%mod)%mod;} 
 return dp[i][j]= ans%mod; }
int main(){
    dp.clear();
    dp.resize(1005,vector<int>(1005, -1));
    int n;
    cin>>n;
    vector<vector<char> > v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    } 
     if(v[0][0]=='*')cout<<0;
    else if(n==1 && v[0][0]=='.')cout<<1;
    //cout<<endl<<endl;
   
    else cout<< f(v,1,0)+f(v,0,1);
}