#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n,m, a[101][101], visited[101][101], hour, lastPieces, ny, nx, cnt = 1;

void dfs(int y,int x){
    visited[y][x] = 1;
    if(a[y][x] == 1)
    {
        a[y][x] = cnt;
       cnt++;
       return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue; 
        dfs(ny,nx);
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(0,0);

    for(int i = 0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}