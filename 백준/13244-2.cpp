#include<bits/stdc++.h>

using namespace std;

int t,n,m,a,b, visited[1004],cnt;
vector<int> adj[1004];

void dfs(int here){
    visited[here] = 1;
    for(int there: adj[here]){
        if(!visited[there]) dfs(there);
    }
    return ;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        fill(visited,visited+1004,0);
        for(int i=1; i<=n; i++) adj[i].clear();
        cnt=0;

        for(int i=0; i<m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1; i<=n;i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }

        if(m==n-1 && cnt==1) puts("tree");
        else puts("graph");
    }
    return 0;
}