#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};

int n, k, L, playTime, dir, appleCnt, x, y, cmdCnt; 
int a[104][104], visited[104][104];
vector<pair<int,int>> apple;
vector<pair<int,char>> command;
queue<pair<int,int>> snake;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<k; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        a[temp1-1][temp2-1] = 1;
    }

    cin>>L;
    for(int i=0;i<L;i++){
        int temp1;
        char temp2;
        cin>>temp1>>temp2;
        command.push_back({temp1, temp2});
    }

    snake.push({0,0});
    visited[0][0] = 1;

    while(true){
        playTime++;

        // 앞에 칸 체크
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 몸에 부딪히거나 벗어나면 stop
        if(ny<0||nx<0||ny>=n||nx>=n) break;
        if(visited[ny][nx]) break;

        // 다음칸 전진
        snake.push({ny,nx});
        visited[ny][nx] = 1;

        // 꼬리 처리
        if(a[ny][nx] == 1){
            //사과 있으니까 snake 건들 ㄴㄴ. 그대~로
            a[ny][nx] = 0;
            //appleCnt++;
        }
        else{
            //없으니까 꼬리는 비워주기
            auto tail = snake.front();
            snake.pop();
            visited[tail.first][tail.second] = 0; 
        }
        
        y = ny; x = nx;


        //if(appleCnt == k) break;
        if(cmdCnt<command.size() && playTime == command[cmdCnt].first){
            //cout<<playTime<<'\n';

            //방향전환
            if(command[cmdCnt].second =='L'){
                dir = (dir+3)%4;
            }
            else{
                dir = (dir+1)%4;
            }
            cmdCnt++;
        }
    }

    cout<<playTime<<'\n';
    return 0;
}