#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// curdir = 0 - 가로, 1 - 세로, 2 - 대각
int d[3][3] ={
    {0,2,-1},
    {1,2,-1},
    {0,1,2}
};

int dy[3] = {0,1,1};
int dx[3] = {1,0,1};
int start_x = 0, start_y = 1;

int n, visited[20][20], testmap[20][20];


ll solve(int y, int x, int curDir){

    if(y==n-1 && x == n-1) return 1;

    ll sum = 0;
    for(int i=0; i<3; i++){
        int nd = d[curDir][i];
        if(nd==-1) continue;

        int ny = y+dy[nd];
        int nx = x+dx[nd];

        if(ny>=n||nx>=n) continue;
        //if(visited[ny][nx])
        if(testmap[ny][nx]==1) continue;
        if(nd==2){
            if(testmap[y+1][x]==1||testmap[y][x+1]==1) continue;
        } 

        sum += solve(ny,nx,nd);

    }

    return sum;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>testmap[i][j];
        }
    }

    solve(start_x, start_y, 0);

    cout<<solve(0,1,0)<<'\n';

}