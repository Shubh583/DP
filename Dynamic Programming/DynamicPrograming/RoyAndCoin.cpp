#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>f(n+1,0);
    int m;
    cin>>m;
    vector<int>l(n+1,0),r(n+1,0);
    for(int i=0;i<m;i++){
        int L,R;
        cin>>L>>R;
        l[L]++;
        r[R]++;
    }
    f[1]=l[1];
    for(int i=2;i<=n;i++){
        f[i]=l[i]+f[i-1]-r[i-1];
    }
    vector<int>c(1000005,0);
    for(int i=0;i<=n;i++){
        c[f[i]]++;
    }
    for(int i=c.size()-2;i>=0;i--){
        c[i]=c[i]+c[i+1];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        cout<<c[x]<<"\n";
    }
}/*
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
*/