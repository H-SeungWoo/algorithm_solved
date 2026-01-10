#include<bits/stdc++.h>

using namespace std;

int n, scv[3], cnt;
int dxyz[6][3]={
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 9, 3},
    {1, 3, 9}
};
struct A{
    int a, b, c;
};
queue<A> q;
bool visited[61][61][61];

void solve(){
    int x=0,y=0,z=0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            tie(x,y,z)= q.front(); q.pop();
            for(int i=0; i<6; i++){
                int nx = max(0,x-dxyz[i][0]);
                int ny = max(0,y-dxyz[i][1]);
                int nz = max(0,z-dxyz[i][2]);
                if(!visited[nx][ny][nz]){
                    q.push({nx,ny,nz});
                    visited[nx][ny][nz] = visited[x][y][z] +1;
                }
            }
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>scv[i];
    }
    q.push({scv[0],scv[1],scv[2]});
    visited[scv[0]][scv[1]][scv[2]] = 1;
    solve();
    cout << visited[0][0][0] -1<<'\n';

    return 0;
}
