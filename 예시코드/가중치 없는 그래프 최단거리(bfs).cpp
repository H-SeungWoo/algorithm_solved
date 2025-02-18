#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[101][101];
bool test_map[101][101];
int n, m, y, x, start_y, start_x, end_y, end_x, ret;

void BFS(int start_y, int start_x)
{
    queue<pair<int,int>> q;
    visited[start_y][start_x] = 1;
    q.push({start_y, start_x});
    
    while(q.size())
    {
        tie(y, x) = q.front(); // tie를 통해 바로 언패킹
        q.pop();
   
        for(int i =0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(test_map[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = visited[y][x] +1;
                q.push({ny,nx});
            }            
        }
    }   
}

int main()
{
    cin >> n >> m;
    cin >> start_y >> start_x;
    cin >> end_y >> end_x;

    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>test_map[i][j];
        }
    }
    BFS(start_y, start_x);

    cout << visited[end_x][end_y] << '\n';

 
    // 시작지점으로부터 거리 디버깅
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << visited[i][j] <<' ';
        }
        cout << '\n';
    }  

    return 0;
}