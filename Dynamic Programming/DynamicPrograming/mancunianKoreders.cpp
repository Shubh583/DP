 # define ll long long int
#include <bits/stdc++.h>
using namespace std;
 ll dp[2005][2005][8]; // array ko aise pass krte h
 ll f(int *a , int *b, int n, int m, int i,int j , int k){
	if(i>=n)return 0;
	if(j>=m)return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	ll res=0;
	if(a[i]==b[j]){
		res= 1+ f(a,b,n,m,i+1,j+1,k);
	}
	else {
		 if(k>0){
			res= 1+f(a,b,n,m,i+1,j+1,k-1);
		 }
		  res= max (res,f(a,b,n,m,i+1,j,k));
		  res= max (res,f(a,b,n,m,i,j+1,k));
	}  return dp[i][j][k]=res;
 }
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	int a[n];
	memset(dp,-1, sizeof dp);
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	 int b[m];
	for(int i=0;i<m;i++) cin>>b[i];
	cout<< f(a,b,n,m,0,0,k);
}