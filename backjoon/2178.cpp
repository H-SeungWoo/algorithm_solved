#include<bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int a[100][100], visited[100][100], n, m, x, y;

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size())
    {
        tie(y,x) = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny >= n || nx <0 || nx >= m || a[ny][nx] == 0) continue;
            if(visited[ny][nx] != 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[n-1][m-1] <<'\n';
    return 0;
}