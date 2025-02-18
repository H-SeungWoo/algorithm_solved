#include<bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, y, x, ny, nx;
int test_map[104][104];
int visited[104][104];

string buffer;

int main()
{
    cin >> n >> m;

    for(int i =1; i<=n; i++)
    {
        cin>>buffer;
        for(int j=1; j<=m; j++)
        {
            test_map[i][j] = buffer[j-1] -'0';
            //cout<<test_map[i][j] << '\n';
        }
    }

    queue<pair<int, int>> q; 
    q.push({1,1});
    visited[1][1] = 1;

    while(q.size())
    {
        tie(y,x) = q.front(); q.pop();
        
        for(int i=0; i<4; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny<1 || nx <1 || ny > n || nx > m) continue;
            if(test_map[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
        //cout <<  "{"<<q.front().first <<","<< q.front().second<< "}" <<'\n';
    }

    cout << visited[n][m] <<'\n';

    return 0;
}
