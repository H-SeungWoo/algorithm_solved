#include<bits/stdc++.h>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n,m, a[1004][1004], visited[1004][1004], day, cnt0;
queue<pair<int,int>> ripes_q, ripesTemp_q;

void Q_clear(queue<pair<int,int>> &q){
    queue<pair<int,int>> empty;
    swap(q, empty);
}

int main(){
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j]==1) ripes_q.push({i,j});
            if(a[i][j]==0) cnt0++;
        }
    }

    int y=0,x=0;
    while(true){
        while(ripes_q.size()){
            tie(y,x) = ripes_q.front(); ripes_q.pop();
            visited[y][x] = 1;
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(visited[ny][nx]) continue;
                if(a[ny][nx]==0){
                    visited[ny][nx] = 1;
                    ripesTemp_q.push({ny, nx});
                    a[ny][nx] = 1;
                    cnt0--;
                }
            }
        }
        if(!ripesTemp_q.size()) break;
        day++;
        ripes_q=ripesTemp_q;
        Q_clear(ripesTemp_q);
    }

    if(cnt0!=0) cout<<-1<<'\n';
    else cout << day <<'\n';

    return 0;
}