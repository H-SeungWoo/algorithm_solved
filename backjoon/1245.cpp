#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[4] = {0, 1, 1, 1, 0, -1, -1, -1};

int n,m, a[104][74], visited[104][74], b[104][74];

bool solve(int y, int x, int height){
    bool higher = false;
    visited[y][x] = 1;
    int ret = 0;

    for(int i=0; i<8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue;

        if(a[ny][nx] < height){
            visited[ny][nx] = 1;
        }
        else if(a[ny][nx] == height){
            visited[ny][nx] = 1;
            higher = solve(ny, nx, height);
        }
        else if(a[ny][nx] > height){
            higher = true;
        }
    }

    return higher;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }


}