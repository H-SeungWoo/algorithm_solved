#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int n, m, h, a[104][104][104], visited[104][104][104], cnt0, z, x, y, day;
vector<tuple<int, int, int>> tomatos;
queue<tuple<int, int, int>> q, q2;

int main()
{
    cin >> m >> n >> h;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[k][i][j];
                if (a[k][i][j] == 0)
                    cnt0++;
                if (a[k][i][j] == 1)
                {
                    tomatos.push_back({k, i, j});
                    visited[k][i][j] =1;
                }
            }
        }
    }


    for (auto tiii : tomatos)
    {
        q.push({get<0>(tiii), get<1>(tiii), get<2>(tiii)});
    }

    while (true)
    {
        while (q.size())
        {
            tie(z, y, x) = q.front();
            q.pop();
            for (int i = 0; i < 6; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nz = z + dz[i];

                if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;
                if (visited[nz][ny][nx]) continue;
                if(a[nz][ny][nx]!=0) continue;

                visited[nz][ny][nx] = visited[z][y][x] +1;
                a[nz][ny][nx] = 1;
                cnt0--;
                q2.push({nz,ny,nx});
            }
        }
        if(q2.empty()) break;
        day++;
        swap(q, q2);
    }

    if(cnt0 != 0 ) cout<< -1 <<'\n';
    else cout << day <<'\n';

    // for (int k = 0; k < h; k++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             cout << a[k][i][j] <<" ";
    //         }
    //         cout <<'\n';
    //     }
    // }
}