#include<bits/stdc++.h>

using namespace std;

int dy[] ={-1,0,1,0};
int dx[] ={0,1,0,-1};
int n,m, a[1004][1004], visited[1004][1004][2], ret;
struct b{
    int y,x,b;
};

void solve(){
    queue<b> q;
    bool isBroken;

    int y=0,x=0,b=0;
    q.push({y,x,b});
    visited[y][x][b] = 1;

    while(q.size()){
        tie(y,x,b) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(a[ny][nx]==1){
                if(visited[ny][nx][1]) continue;
                visited[ny][nx][1] = visited[y][x][0]+1;
                q.push({ny,nx});
            }
            else{
                if(visited[ny][nx][0]) continue;
                visited[ny][nx][0] = visited[y][x][0] +1;
                q.push({ny,nx});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    solve();
    ret = min(visited[n-1][m-1][0], visited[n-1][m-1][1]);
    if(ret==0) cout<<-1<<'\n';
    else cout<<ret<<'\n';

    return 0;
}