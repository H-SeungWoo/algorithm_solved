#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dy[4] = {-1, 0 , 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, ret=INF, a[14][14], visited[14][14];
// 꽃이 겹치면 안되고,
// 한 점을 기준으로 상하좌우를 신경써야하고,
// 완탐으로 최소값을 구해야함.

bool check(int y, int x){
    if(visited[y][x]) return false;

    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
            
        if(visited[ny][nx]) return false;
        
    }

    return true;
}

int flower(int y, int x, bool bOnOff){

    int cash = a[y][x];
    
    if(bOnOff){
        
        visited[y][x] = 1;
        
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            visited[ny][nx]=1;
            cash+=a[ny][nx];
        }
    }
    else{

        visited[y][x] = 0;
        
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            visited[ny][nx]=0;
            cash+=a[ny][nx];
        }        
    }

    return cash;
}

void solve(int cash, int cnt){
    //cout << "cnt: " << cnt <<", cash: "<< cash << '\n';
    if(cash>=ret) return;
    if(cnt==3) {
        ret=min(cash,ret);
        //cout<< ret <<'\n';
        return;
    }


    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            if(check(i,j)){
                cash += flower(i, j, 1);
                cnt++;
                solve(cash, cnt);
                cash -= flower(i, j, 0);
                cnt--;
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }


    solve(0,0);

    cout<<ret<<'\n';
}