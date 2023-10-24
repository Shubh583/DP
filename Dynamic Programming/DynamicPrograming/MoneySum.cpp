#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > s;
vector<int>w;
int f(vector<int>&v, int id,vector<int>answer,int u){
  if(id==v.size()){ s.push_back(answer);
   return 0;
 }
 w.push_back(u);
 int ans=0;
 ans=f(v,id+1,answer,u);
answer.push_back(v[id]);
ans=f(v,id+1,answer,u+v[id]);
//4 2 5 2 7 7 2 9 6 5 2 7 11 2 13 
 return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);vector<int>answer;
    for(int i=0;i<n;i++)cin>>v[i];
   f(v,0,answer,0);
// for(int i=0;i<s.size();i++){ int ans=0;
//   for(int e=0;e<s[i].size();e++){
//   ans+=s[i][e];
//   } 
//    cout<<ans<<"  ";
// }
for(int i=0;i<w.size();i++)cout<<w[i]<<" ";
}// 2 4 5 6 7 8 9 11 13