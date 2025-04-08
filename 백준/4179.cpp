#include<bits/stdc++.h>

using namespace std;

constexpr int INF = INT_MAX/2;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int n, m, y, x, sy, sx, ret;
char a[1004][1004];
int fire_visited[1004][1004], player_visited[1004][1004];

int main()
{
    cin >> n >> m;
    queue<pair<int, int>> q;
    fill(&fire_visited[0][0], &fire_visited[0][0]+1004*1004, INF);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='J') 
            {
                sy = i; 
                sx = j;
            }
            if(a[i][j]=='F') 
            {
                fire_visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }

    while(q.size())
    {
        tie(y, x)= q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || ny>= n || nx >= m) continue;
            if(a[ny][nx] == '#' || fire_visited[ny][nx] != INF) continue;
            
            fire_visited[ny][nx] = fire_visited[y][x]+1;
            q.push({ny, nx});
        }
    }

    player_visited[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        if( y == n-1 || x == m-1 || y == 0 || x == 0)
        {
            ret = player_visited[y][x];
            break;
        }

        for(int i= 0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || ny>=n || nx >= m) continue;
            if(a[ny][nx] == '#' || player_visited[ny][nx]) continue;
            if(fire_visited[ny][nx] <= player_visited[y][x]+1) continue;
            player_visited[ny][nx] = player_visited[y][x] +1;
            q.push({ny,nx}); 
        }
    }

    if(ret != 0) cout << ret <<'\n';
    else cout << "IMPOSSIBLE \n";

    return 0;
}
