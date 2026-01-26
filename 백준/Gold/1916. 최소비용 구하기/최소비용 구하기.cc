#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<pair<int,int>> adj[100004];
vector<int> dist(100004, INF);

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        int here_w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u] < here_w) continue;

        for(auto &[v, weight]: adj[u]){
            int new_w = here_w + weight;
            if(new_w < dist[v]){
                dist[v] = new_w;
                pq.push({new_w, v});
            }
        }
    }
}

int main(){
    int n,m, start, end;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>> u >> v >> w;
        adj[u].push_back({v,w});
    }

    cin>>start>>end;

    dijkstra(start);

    cout<<dist[end]<<'\n';
    return 0;
}