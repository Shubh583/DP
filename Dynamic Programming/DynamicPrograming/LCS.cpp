#include<bits/stdc++.h>
using namespace std;

 string output="";
vector< vector<int> > dp;
int f(string &s,string &t, int i, int j,string& ans){
    //if(output.size()<ans.size())output=ans;
    if(i>=s.size())return 0;
    if(j>=t.size())return 0;
   //if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){//ans+=s[i]; 
      return  dp[i][j]= 1+f(s,t,i+1,j+1,ans+=t[j]);
    }

       else return dp[i][j] = max(f(s,t,i,j+1,ans),f(s,t,i+1,j,ans));
    
    
}
int main(){
  string s, t;
    cin>>s;
    cin>>t;
    dp.clear();
    dp.resize(3005,vector<int>(3005,-1));
   string ans="";
   f(s,t,0,0,ans);
   //reverse(output.begin()+1,output.end());
   cout<<ans<<" ";
}