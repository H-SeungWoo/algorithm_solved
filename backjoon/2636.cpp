#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n,m, a[101][101], visited[101][101], hour, pieces, ny, nx, cnt = 1;
bool flag;
vector<pair<int, int>> cList;
 
void dfs(int y,int x){
    visited[y][x] = 1;
    if(a[y][x] == 1)
    {
        cList.push_back({y,x});
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
        dfs(ny,nx);
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    while(true)
    {
        flag = false;
        hour++;
        pieces = 0;
        fill(&visited[0][0], &visited[0][0]+101*101, 0);
        cList.clear();

        dfs(0,0);

        for(pair<int, int> pii: cList)
        {
            pieces++;
            a[pii.first][pii.second] = 0;
        }

        for(int i =0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j] == 1)
                {
                    flag = true;
                }
            }
        }

        if(!flag) break;
    }

    cout << hour <<'\n';
    cout << pieces <<'\n';

    return 0;
}