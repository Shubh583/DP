#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int f(int n){
    if(n==0|| n==1)return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]= f(n-1)+f(n-2);
    }
    //dp[0]=0; dp[1]=1;
//i =2 i,=n;i++ 
    int it(int n){
      int a=0;
      int b=1;
      int c=0;int i=0;
      while(i<=n){
      cout<<c<<" "; 
        a=b;
        b=c;
        c=a+b;
        i++;
     }
 return c;


    }
int main(){
    int n;
   // cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    //cout<<f(n);
    cout<<it(8);
}