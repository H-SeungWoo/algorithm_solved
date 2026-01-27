#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 1e9;
vector<pair<int,int>> adj[200004];
vector<ll> dist(200004, INF), dist_v1(200004, INF), dist_v2(200004, INF);
ll ret;

void dijkstra(int start, vector<ll>& vec){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vec[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int here_w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(here_w > vec[u]) continue;

        for(auto &[v, weight]: adj[u]){
            int new_w = here_w + weight;
            if(new_w < vec[v]){
                vec[v] = new_w;
                pq.push({new_w, v});
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int v1,v2;
    cin>>v1>>v2;

    dijkstra(1, dist);
    dijkstra(v1, dist_v1);
    dijkstra(v2, dist_v2);

    ret = min(dist[v2]+dist_v2[v1]+dist_v1[n], dist[v1]+dist_v1[v2]+dist_v2[n]);
    
    if(ret>=INF) cout<<-1<<'\n';
    else cout<<ret<<'\n';

    return 0;

}