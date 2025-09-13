#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, cnt, ret=1;
vector<string> borad; 
bool visited[26];

void dfs(int y, int x, int depth){   
    ret = max(ret, depth);

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[borad[ny][nx]-'A']) continue;

        visited[borad[ny][nx]-'A'] = true;
        dfs(ny, nx, depth+1);
        visited[borad[ny][nx]-'A'] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
            cin>>borad[i];
    }

    visited[borad[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << ret <<'\n';
    return 0;
}