#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int t, n, m, k, x, y, nx, ny, cnt;

int test_map[52][52];
int visited[52][52];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if(test_map[ny][nx] == 1 && !visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> t;
    while(t--)
    {
        memset(test_map, 0 , sizeof(test_map));
        memset(visited, 0 , sizeof(visited));
        cnt = 0;

        cin >> m >> n >> k;
        for(int i =0; i<k; i++)
        {
            cin >> x >> y;
            test_map[y][x] = 1;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(test_map[i][j] == 1 && !visited[i][j])
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}