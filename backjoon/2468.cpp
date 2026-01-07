#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, x, y, nx, ny, cnt, ret, h = 100;
int test_map[101][101];
bool visited[101][101];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i = 0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(test_map[ny][nx] > h && !visited[ny][nx])
        {
            dfs(ny,nx);
        }
    }
}

int main ()
{
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> test_map[i][j];
        }
    }

    while(h--) // 높이가 1부터 100까지
    {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(test_map[i][j] > h && !visited[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        if(cnt > ret) ret = cnt;
    }

    cout << ret << '\n';    
}