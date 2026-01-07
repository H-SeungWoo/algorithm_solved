#include<bits/stdc++.h>

using namespace std;

int m,n, visited[10];
vector<int> v, ret;

void solve(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<ret[i]<<" ";
        }
        cout<<'\n';
        return ;
    }


    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i]=1;
        ret.push_back(v[i]);
        solve(depth+1);
        visited[i]=0;
        ret.pop_back();

    }
}

int main(){
    cin>>n>>m;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    solve(0);
    return 0;
    
}