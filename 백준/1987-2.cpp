#include<bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int r, c,  ret=0;
char a[21][21];
void solve(int y, int x, int mask, int cnt){
    ret = max(cnt, ret);
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
        
        int _next = (1<<(int)(a[ny][nx]-'A'));
        if(mask&_next) continue;
        
        solve(ny, nx, mask|_next ,cnt+1);
    }
    return;
}

int main(){
    cin >> r>> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }

    solve(0,0,1<<(int)(a[0][0]-'A'),1);
    cout<<ret<<'\n';
    return 0;
}