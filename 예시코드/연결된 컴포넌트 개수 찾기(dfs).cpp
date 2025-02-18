#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n,m, cnt, ny, nx;
int test_map[101][101];
bool visited[101][101];

void DFS(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny< 0 || nx < 0 || ny > n || nx >= m) continue;
        if(test_map[ny][nx] == 1 && !visited[ny][nx])
        {
            DFS(ny, nx);
        }
    }
    return;
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> test_map[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(test_map[i][j] == 1 && !visited[i][j])
            {
                cnt++; 
                DFS(i, j);
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}
