#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, l, r, day, sumPeople, sumContry;
int a[54][54], visited[54][54];
vector<pair<int, int>> uniteList;
bool canMove;

void solve(int y, int x)
{
    if(visited[y][x]) return;
    sumPeople = 0;
    sumContry = 0;

    queue<pair<int, int>> q;
    visited[y][x] = 1;
    uniteList.push_back({y,x});
    q.push({y,x});

    while(q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        sumPeople += a[y][x];
        sumContry++;
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
            int diff = abs(a[ny][nx] - a[y][x]);
            if(l <= diff && diff <= r && !visited[ny][nx])
            {
                canMove = true;
                q.push({ny, nx});
                uniteList.push_back({ny,nx});
                visited[ny][nx]=1;
            }

        }
    }

    for(auto contry: uniteList)
    {
        a[contry.first][contry.second] = sumPeople/sumContry;
        //cout << "(y,x): (" << contry.first <<"," << contry.second<<") sumPeople: " << sumPeople << ", sumContry: " << sumContry << ", result: " << a[y][x] << '\n';
    }
}


int main()
{
    cin >> n >> l >> r;
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }

    while(true)
    {
        fill(&visited[0][0], &visited[0][0] +54*54, 0);

        canMove = false;

        for(int i =0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                solve(i, j);
                uniteList.clear();
            }
        }


        if(!canMove) break;



        // cout<<'\n';
        // for(int i =0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        day++;
    }

    cout << day <<'\n';
    return 0;
}