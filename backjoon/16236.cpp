#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int n, ans, sizeOfBaby = 2, cnt_eat, shark_x, shark_y, nOfEat;
int board[24][24];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                shark_y=i,shark_x=j;
            }
        }
    }

    // 이동 불가 -> 끝
    // 도착 -> 크기 증가?
    
    while(true){
        // 지금 잡을 수 있는 물고기 개수 체크
        vector<pair<int,int>> canEat;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] > 0 && board[i][j]<sizeOfBaby && board[i][j]< 9)
                canEat.push_back({i,j});
            }
        }
        
        // 없으면 -> 끝, 있으면 진행
        if(canEat.empty()) break;
        
        // 이동가능한지 체크 + 거리계산 (bfs)
        int visited[24][24] = {0};
        
        queue<pair<int,int>> q;
        q.push({shark_y,shark_x});
        visited[shark_y][shark_x] = 1;
        while(q.size()){
            int y=0,x=0;
            tie(y,x) = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if(ny<0||nx<0||ny>=n||nx>=n) continue;
                if(visited[ny][nx]) continue;
                if(board[ny][nx] > sizeOfBaby) continue;
                
                visited[ny][nx] = visited[y][x]+1;
                q.push({ny,nx});
            }
            
        }
        
        
        // 제일 가까운 곳으로 이동
        //거리가 똑같다면 자연스럽게 좌측, 상단 우선 됨. (for문에서 0부터 넣었음)
        int dist=1e9;
        int ny=-1, nx=-1;
        for(pair<int,int> posFood: canEat){
            if(!visited[posFood.first][posFood.second]) continue;
            if(dist>visited[posFood.first][posFood.second]-1){
                ny=posFood.first;
                nx=posFood.second;
                dist = visited[ny][nx]-1;
            }
        }

        // 먹이까지 갈 수가 없음
        if(dist == 1e9) break;

        ans+=visited[ny][nx]-1;
        board[ny][nx] = 0;
        nOfEat++;
        if(nOfEat==sizeOfBaby){
            sizeOfBaby++;
            nOfEat=0;
        }

        // 상어의 위치정보 업데이트
        board[ny][nx] = 9;
        board[shark_y][shark_x] = 0;
        shark_y=ny,shark_x=nx;
    }

    cout<<ans<<'\n';
    return 0;
}