#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, k, visited[100004];

void solve(){

    queue<int> q;
    q.push(n);
    visited[n] =1;
    int x=0;
    while(q.size()){
        x = q.front(); 
        q.pop();
        for(int nx: {x-1, x+1, x*2}){
            if(nx<0 || nx>100000) continue;
            if(visited[nx]) continue;
            visited[nx] = visited[x]+1;
            //cout<<x<<"->"<<nx<<'\n';
            q.push(nx);
        }

        if(visited[k]) break;
    }
    return;
}


int main(){

    cin>>n>>k;
    solve();
    cout<<visited[k]-1<<'\n';
    return 0;
}