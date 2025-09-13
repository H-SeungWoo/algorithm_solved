#include<bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, sx, sy, ex, ey, visited[304][304], cnt;
char classRoom[304][304];
bool findShrap;

void dfs(int y, int x)
{
    if(findShrap) return;
    
    visited[y][x] = 1;
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if(visited[ny][nx]) continue;
        if(classRoom[ny][nx] == '#')
        {
            //cout<<"find #"<<'\n';
            visited[ny][nx] = 1;
            findShrap = true;
            
        }
        else if(classRoom[ny][nx] == '1')
        {
            //cout<<"1" << '\n';
            classRoom[ny][nx] = '0';
            visited[ny][nx] = 1;
        }
        else // (classRoom[ny][nx] == '0')
        {
            //cout<<"dfs!" <<'\n';
            dfs(ny, nx);
        }

    }
}

int main()
{
    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex;

    sx--; sy--; ex--; ey--;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> classRoom[i][j];
        }
    }

    while(!findShrap)
    {
        //cout<<"turn: " << cnt +1<<'\n';
        fill(&visited[0][0], &visited[0][0]+304*304, 0);
        dfs(sy, sx);
        cnt++;        
    }

    cout << cnt << '\n';
}