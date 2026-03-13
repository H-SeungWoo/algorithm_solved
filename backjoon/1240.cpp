#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int,int>> a[1004];
int n,m, visited[1004];

int solve(int x, int goal){
    queue<int> q;

    q.push(x);
    visited[x] = 1;
    while(q.size()){
        int here = q.front();
        if(here== goal) break;
        q.pop();
        for(auto& [next, cost]: a[here]){
            if(visited[next]) continue;
            visited[next] = visited[here]+cost;
            q.push(next);
        }
    }
    return visited[goal]-1;
}
 
int main(){
    cin>>n>>m;
 
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }

    while(m--){
        int from, to;
        cin>>from>>to;

        fill(visited, visited+1004, 0);
        cout<<solve(from, to)<<'\n';
    }

    return 0;
}