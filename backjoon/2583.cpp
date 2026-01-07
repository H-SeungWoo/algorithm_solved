#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int m,n,k, nx, ny, cnt, area;
int test_map[101][101];
int visited[101][101];
vector<int> areas;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0|| nx<0 || ny >= m || nx >= n) continue;
        if(test_map[ny][nx]&&!visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
    area++;

}

int main()
{
    cin >> m >> n >> k;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            test_map[i][j] = 1;
        }
    }

    while(k--)
    {
        int kx1,ky1,kx2,ky2;
        cin >> kx1 >> ky1 >> kx2 >>ky2;
        for(int i = ky1; i<ky2; i++)
        {
            for(int j = kx1; j<kx2; j++)
            {
                test_map[i][j] = 0;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(test_map[i][j] == 1 && !visited[i][j])
            {
                area = 0;
                dfs(i,j);
                areas.push_back(area);
                cnt++;
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout<<cnt<<'\n';

    for(int a: areas)
    {
        cout << a <<' ';
    }

    /* 맵 디버깅
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << test_map[i][j] << ' '; 
        }
        cout << '\n';
    }
    */

    return 0;
}