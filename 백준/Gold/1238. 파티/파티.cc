#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<pair<int,int>> adj[10004], r_adj[10004];
vector<int> dist(10004,INF), r_dist(10004,INF);
int n,m,X,ret;

void dijkstra(int start, vector<pair<int,int>> town_adj[], vector<int>& road_dist ){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    road_dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(here_cost > road_dist[u]) continue;

        for(auto &[v, w]: town_adj[u]){
            int next_cost = here_cost + w;
            if(next_cost < road_dist[v]){
                road_dist[v]=next_cost;
                pq.push({next_cost, v});
            }
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>X;

    for(int i=0; i<m; i++){
        int u, v, t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        r_adj[v].push_back({u,t});
    }

    dijkstra(X, adj, dist);
    dijkstra(X, r_adj, r_dist);

    for(int i=1; i<=n; i++){
        ret=max(ret, dist[i]+r_dist[i]);
    }

    cout<<ret<<'\n';
}