#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<bool>dp(1000005,0);
    int m;
    int k,l;
    cin>>m>>k>>l;
    dp[1]=1;
    dp[k]=1; 
    dp[l]=1;
    for(int i=2;i<=100000;i++){
        if(i==k || i==l)continue;
        dp[i]=!((dp[i-1]) && ((i-k>=1)?dp[i-k]:1) && ((i-l>=1)?dp[i-l]:1));
    }
//ABAAB
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        if(dp[n]==1)cout<<"A";
        else cout<<"B";
    }
}