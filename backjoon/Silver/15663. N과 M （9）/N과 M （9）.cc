#include<bits/stdc++.h>

using namespace std;

int n,m, a[8], visited[8];
vector<int> ret;

void solve(int depth){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<ret[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    int prev = 0;

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        if(prev==a[i]) continue;

        visited[i] = 1;
        ret.push_back(a[i]);
        solve(depth+1);
        visited[i] = 0;
        ret.pop_back();

        prev=a[i];
        
    }
    return;
}



int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);

    solve(0);
    return 0;
}