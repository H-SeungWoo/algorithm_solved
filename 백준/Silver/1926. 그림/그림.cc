#include<bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0 , 1, 0};
int dx[] = {0, 1, 0, -1};

int a[504][504], visited[504][504], part[504][504], mx, cnt, m, n;

int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx]==0) continue;
        ret += dfs(ny,nx);
    }
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]&&a[i][j]==1){
                mx = max(mx, dfs(i,j));
                cnt++;
            }
        }
    }

    cout<<cnt<<'\n';
    cout<<mx<<'\n';
    return 0;
}
