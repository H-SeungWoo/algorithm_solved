#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int n,m, world[104][104], visited[104][104], ans;

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(world[ny][nx]==1) visited[ny][nx]++;
        else{
            if(visited[ny][nx]) continue;
            dfs(ny, nx);
        }
    }
}

bool solve(){
    int cnt=0;

    // dfs 실행 후 없어질 치즈 위치 찾기
    dfs(0,0);
    // visited가 2 이상인 치즈는 0으로 바꾸기.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]>=2){
                world[i][j] = 0;
                cnt++;
            }
        }
    }
    return cnt>0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>world[i][j];
        }
    }

    while(true){
        fill(&visited[0][0], &visited[0][0]+104*104, 0);
        if(!solve()){
            break;
        }

        ans++;
    }

    cout<<ans<<'\n';
}