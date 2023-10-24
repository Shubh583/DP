#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
char mp[105][105];
ll dp[105][105][105];
int n; int m;
ll f(int i, int j , int x, int y){
    
if(i>n or j>m or x>n or y>m or mp[i][j]=='#' or mp[x][y]=='#')return 0;
if(i==n and j==m){
    return mp[i][j]=='*';
}
if(dp[i][j][x]!=-1)return dp[i][j][x];
ll result=INT_MIN;
result=max(result,f(i+1,j,x+1,y));
result=max(result,f(i+1,j,x,y+1));
result=max(result,f(i,j+1,x+1,y));
result=max(result,f(i,j+1,x,y+1));

result+=(mp[i][j]=='*');
result+=(mp[x][y]=='*');
//remove repitation
if(i==x and j==y and mp[i][j]=='*')result--;

return dp[i][j][x]=result;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        
        cin>>m>>n;
        //memset(mp,0,sizeof mp);
        memset(dp,-1, sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        } 
        cout<<f(1,1,1,1)<<endl;
    }
}