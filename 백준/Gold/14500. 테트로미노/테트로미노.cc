#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, a[504][504], ans;
bool visited[504][504];

void solve(int y, int x, int sum, int depth){
    if(depth == 4){
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        int new_sum = sum+a[ny][nx];

        if(depth == 2){
            solve(y, x, new_sum, depth+1);
        }
        solve(ny,nx,new_sum, depth+1);
        visited[ny][nx] = 0;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 1;
            solve(i, j, a[i][j], 1);
            visited[i][j] = 0;
        }
    }

    cout << ans << '\n';
}