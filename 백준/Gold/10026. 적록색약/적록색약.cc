#include<bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, cnt1, cnt2;
char a[104][104];
bool visited[104][104];

void solve1(int y, int x, char ch){
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] == ch){
            //cout<<"dfs\n";
            solve1(ny, nx, ch);
        }
    }
}

void solve2(int y, int x, char ch){
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] == ch){
            solve2(ny, nx, ch);
        }
        else if(ch!='B' && a[ny][nx]!='B') {
            solve2(ny, nx, ch);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    // 일반
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            solve1(i, j, a[i][j]);
            cnt1++;
        }
    }
    
    fill(&visited[0][0], &visited[0][0]+104*104, 0);

    // 색약
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            solve2(i, j, a[i][j]);
            cnt2++;
        }
    }    

    cout<< cnt1 <<' ' << cnt2<<'\n';
    return 0;
}