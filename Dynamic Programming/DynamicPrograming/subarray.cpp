#include<bits/stdc++.h>
using namespace std;
void subarray(vector<int>&v, int i, vector<int>ans){
    if(i==v.size()){for(int i=0;i<ans.size();i++)cout<<ans[i]<<" "; cout<<endl;return;}
    subarray(v,i+1,ans);
    if(ans.size()==0 || ans[ans.size()-1]==v[i-1]){
        ans.push_back(v[i]);
        subarray(v,i+1,ans);

    }
}
int main(){
    vector<int>v={7,2,5,10,8};
    subarray(v,0,{});
}