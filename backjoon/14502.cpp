#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0 , 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[10][10], visited[10][10], ret, ny, nx;
vector<pair<int, int>> virusList, spaceList;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i =0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0|| nx<0 || ny>=n || nx >= m) continue;
        if(a[ny][nx] == 0 && !visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int solve()
{
    fill(&visited[0][0], &visited[0][0]+10*10, 0);
    for(pair<int, int> v: virusList)
    {
        dfs(v.first, v.second);
    }

    int cnt = 0;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]==0 && !visited[i][j]) cnt++;
        }
    }

    return cnt;
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 2) virusList.push_back({i, j});
            if(a[i][j] == 0) spaceList.push_back({i, j});
        }
    }

    for(int i=0; i<spaceList.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            for(int k=0; k<j; k++)
            {
                a[spaceList[i].first][spaceList[i].second] = 1;
                a[spaceList[j].first][spaceList[j].second] = 1;
                a[spaceList[k].first][spaceList[k].second] = 1;
                ret = max(ret, solve());
                a[spaceList[i].first][spaceList[i].second] = 0;
                a[spaceList[j].first][spaceList[j].second] = 0;
                a[spaceList[k].first][spaceList[k].second] = 0;
            }

        }
    }

    cout << ret << "\n";
    return 0;
}