#include<bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
const int INF = 1e9;
int n, m, visited[1504][1504], day=INF, sawnCnt, from_y, from_x, to_y, to_x;
char lakeMap[1504][1504];
vector<pair<int, int>> swanPos;
bool canMeet = false;
// L에서 L로 가는 경로 중 최소의 X를 가지는 개수를 찾자.
// ceil(X/2)이 곧 날짜일 것이다.


void dfs(int y, int x, int x_cnt)
{
    if(x_cnt>day) return;

    if(y==to_y && x==to_x)
    {
        visited[y][x] = 0;
        day = min(x_cnt, day);
        return;
    }

    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[ny][nx]) continue;
        if(lakeMap[ny][nx]=='X') x_cnt++;
        visited[ny][nx] = 1;
        dfs(ny,nx, x_cnt);
        if(lakeMap[ny][nx]=='X') x_cnt--;
        visited[ny][nx] = 0;
    }
}

1500*1500*
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>lakeMap[i][j];
            if(lakeMap[i][j]=='L') 
            {
                //cout << n << " " << m <<'\n';
                swanPos.push_back({i, j});
            }
        }
    }

    tie(from_y,from_x) = swanPos[0];
    tie(to_y,to_x) = swanPos[1];

    dfs(from_y, from_x, 0);

    cout << ceil((double)day/2) << '\n';


    return 0;
}