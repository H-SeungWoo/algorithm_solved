#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<pair<int,int>> adj[20004];
vector<int> dist(20004, INF);

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int here_w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 다른 간선으로부터 오는 u라면
        // dist[u]와 현재 w가 다르다면, (w가 더 크다면)
        // pq.top()에 있던 u는 최단거리가 아닌 다른 간선으로 온 것이다. 
        if(dist[u] != here_w) continue;

        for(auto &[v, weight] : adj[u]){
            int new_w = here_w+ weight;
            if(new_w < dist[v]){
                dist[v] = new_w;
                pq.push({new_w, v});
            }
        }
    }
}

int main(){
    int n, m, start;
    cin >> n>> m>> start;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    dijkstra(start);

    for(int i=1; i<=n; i++){
        if(dist[i]==INF) cout<<"INF\n";
        else cout<<dist[i]<<'\n';
    }

    return 0;
}