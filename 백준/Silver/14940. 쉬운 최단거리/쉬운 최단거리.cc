#include<bits/stdc++.h>

using namespace std;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int n,m, a[1004][1004], visited[1004][1004], y, x; 
queue<pair<int,int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++ ){
            cin>>a[i][j];
            if(a[i][j]==2){
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;

            visited[ny][nx] = visited[y][x]+1;
            q.push({ny,nx});
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]==0) cout << (a[i][j]==1?-1:0) << " ";
            else cout << visited[i][j] -1 << " ";
        }
        cout<< '\n';
    }

    return 0;

}