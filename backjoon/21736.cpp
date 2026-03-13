#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int n, m, cnt;
char a[604][604];
bool visited[604][604];
pair<int,int> startPos;

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[ny][nx]||a[ny][nx]=='X') continue;

        if(a[ny][nx]=='P') cnt++;
        dfs(ny,nx);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j]=='I') startPos={i,j};
        }
    }

    dfs(startPos.first,startPos.second);

    if(cnt) cout<<cnt<<'\n';
    else cout<<"TT\n";

    return 0;
}