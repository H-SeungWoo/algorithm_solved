#include<bits/stdc++.h>

using namespace std;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int r, c, swan_visited[1504][1504], water_visited[1504][1504], day, sx, sy;
queue<pair<int,int>> swanQ, swanTempQ, waterQ, waterTempQ;
char a[1504][1504];

void clearQ(queue<pair<int,int>> &q){
    queue<pair<int,int>> clear;
    swap(q, clear);
}

bool swan_move(){
    int x=0,y=0;
    while(swanQ.size()){
        tie(y,x) = swanQ.front(); swanQ.pop();
        swan_visited[y][x]=1;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=r||nx>=c) continue;
            if(swan_visited[ny][nx]) continue;
            swan_visited[ny][nx] = 1;
            if(a[ny][nx]=='X'){
                swanTempQ.push({ny,nx});
            }
            else if(a[ny][nx]=='.'){
                swanQ.push({ny,nx});
            }
            else{
                return true;
            }
        }
    }
    return false;
}

void water_melt(){
    int x=0, y=0;
    while(waterQ.size()){
        tie(y,x) = waterQ.front(); waterQ.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=r||nx>=c) continue;
            if(water_visited[ny][nx]) continue;
            if(a[ny][nx]=='X'){
                a[ny][nx] = '.';
                water_visited[ny][nx] = 1;
                waterTempQ.push({ny,nx});
            }
        }
    }

    return;
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a[i][j];
            if(a[i][j] =='L') {sy=i; sx=j;}
            if(a[i][j]=='.' || a[i][j]=='L') {
                waterQ.push({i,j});
                water_visited[i][j]=1;
            }
        }

    }
    swanQ.push({sy,sx});
    swan_visited[sy][sx] = 1;

    while(true){
        if(swan_move()) break;
        water_melt();
        swap(waterQ,waterTempQ);
        clearQ(waterTempQ);
        swap(swanQ,swanTempQ);
        clearQ(swanTempQ);
        day++;
    }

    cout <<day<<'\n';
    return 0;
}