#include<bits/stdc++.h>

using namespace std;

int dy[8] = {-1,-1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0 , -1, -1, -1};

typedef long long ll;
ll ret;
int n, board[16][16], cnt;

// n*n에 n개의 퀸이 존재하려면, 각 행에 하나씩은 퀸이 있어야 한다.

// 가로 같으면 안되고, 세로 같으면 안되고, 대각선 같으면 안됨.
// 대각선을 판별하는 로직 -> +1+1,-1-1 / +1-1, -1+1 두 경우.
// 한 점에 대해 x,y의 차가 항상 같다. (x=y 기준 평행이동이니까)
// 우하향 대각선의 경우, 0,0/1,-1/2,-2/ 합이 같다. 
// 즉, 한점에 대하여, 다른 점의 x,y의 차나 합이 같은 경우는 대각선에 있는 선인 것임.
// 그럼. 한 수에 대해서는 항상 고정인가? 1000, 1000과 -1000, -1000은 차가 0. 
// 0,0/1,1/2,2...에 대하여 대각선. 왜냐하면, 차가 0으로 같으니까 
// 1,2의 경우. 1001과 1002와 대각선인데. 차가 1이다. 즉 차가 1인 모든 좌표는 대각선. 


bool check(int y, int x){
    // 행 돌면서, 놓을 수 있는 행 있는지 체크
    for(int i=0; i<y; i++){
        if(board[i][x]) return false;
    }

    // \방향(좌상향)
    for(int i=y-1, j=x-1; i>=0 && j>=0; i--, j--){
        if (board[i][j]) return false;
    }
    
    // /방향(좌상향)
    for(int i=y-1, j=x+1; i>=0&&j<n; i--, j++){
        if(board[i][j]) return false;
    }

    return true;
}

void solve(int row){
    if(row == n) {
        ret++;
        return;
    }

    // dydx를 쓸게 아니라.. 그래프 문제가 아님.
    //

    for(int col=0; col<n; col++){
        if(!check(row, col)) continue; // 놓을 수 없는 위치면
        board[row][col] = 1;
        solve(row+1);
        board[row][col] = 0;
    }

}

int main(){

    cin>>n;

    solve(0);
    
    cout<<ret<<'\n';

}