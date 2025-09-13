#include<bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int R, C, K, visited[6][6], ret;
char testmap[6][6];

void solve(int y, int x, int cnt){
    //cout << "now (y,x) = (" <<y<<","<<x<<")"<<'\n'; 
    if(cnt==K){
        if(y==0 && x==C-1) {
            //cout << "ret++ !!! -";
            ret++;
        }
        //cout<<"cnt == k" <<'\n';
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=R||nx>=C) continue;
        if(visited[ny][nx]) continue;
        if(testmap[ny][nx] == 'T') continue;
        
        visited[ny][nx]=1;
        solve(ny, nx, cnt+1);
        visited[ny][nx]=0;
    }

}
int main(){
    cin >> R >> C >> K;
    for(int i=0; i<R; i++){
        string temp;
        cin>> temp;
        for(int j=0; j<C; j++){
            testmap[i][j] = temp[j];
        }
    }

    visited[R-1][0]=1;
    solve(R-1,0,1);
    cout<<ret<<'\n';

    return 0;
}