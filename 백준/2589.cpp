#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, dist, visited[52][52]; 
char a[52][52];

int solve(int y, int x)
{
    if(a[y][x] == 'W') return 0;
    
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});

    while(!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {  
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || ny>=n || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] == 'L')
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
                dist = max(visited[ny][nx]-1, dist);
            }
        }
    }

    return dist;

}

int main()
{
    cin >> n >> m;
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            fill(&visited[0][0], &visited[0][0]+52*52, 0);
            dist = max(dist, solve(i, j));
        }
    }
    cout << dist << '\n';

    return 0;

}