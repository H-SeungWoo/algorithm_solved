#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, cnt, ret=1;
char a[22][22]; 
bool visitedChar[26],visited[22][22];

void dfs(int y, int x)
{   
    //cout << "start from - " << a[y][x] << " :: now cnt - "<< cnt <<'\n';
    for(int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        //cout<<a[ny][nx] << "   forforfor" <<'\n';
        if(visited[ny][nx] || visitedChar[a[ny][nx]-'A']) continue;
// C -> cnt = 1, -> A cnt++, visited
// A - cnt = 2, -> D cnt++, visited
// D -> cnt = 3 -> A,Cx
        //cout << a[y][x] << " -> " << a[ny][nx]<< " i = " << i<<'\n';
        
        cnt++;
        visitedChar[a[ny][nx]-'A'] = true;
        //visited[ny][nx] = 1;
        dfs(ny, nx);
        ret = max(cnt, ret);
        cnt--;
        visitedChar[a[ny][nx]-'A'] = false;
        //visited[ny][nx] = 0;

    }
    //cout << "dfs ended" <<'\n';
    
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        
        {
            cin>>a[i][j];
        }
    }

    cnt++;
    visitedChar[a[0][0]-'A'] = true;
    //visited[0][0] = 1;
    dfs(0,0);
    cout << ret <<'\n';
}