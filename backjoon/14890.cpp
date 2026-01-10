#include<bits/stdc++.h>

using namespace std;

int n, l, a[104][104],cnt=0, visited[104];

// 최대 200개의 길 *100. -> 20000. 완탐가능 

// 첫 행 -> 다음행 같으면 계속. ( 카운트 세기)
//                  다르면 비교. 1보다 차이나면 0return.
//                차이가 1이면 카운트랑 비교

int solve_row(int y){
    fill(&visited[0], &visited[0]+104, 0);
    int now = a[y][0], b=0;
    for(int i=1; i<n; i++){
        b++;
        if(now == a[y][i]){
            continue;
        }
        else{
            if(abs(now-a[y][i]) != 1) {
                return 0; 
            }

            if(now>a[y][i]){//아래로 내려갈때
                if(i>n-1) return 0; // 끝단에 놓을 수 없을때
                for(int j=1; j<l; j++){ // 밑에 발판을 놓을 수 있을 만큼 깔려있는지
                    if(a[y][i]==a[y][i+j]) continue;
                    return 0;
                }
                for(int j=0; j<l; j++){
                    visited[i+j] = 1;
                }
            }
            else if(now<a[y][i]){ // 위로 올라갈때
                if(b<l) return 0;
                for(int j=1; j<=l; j++){
                    if(visited[i-j]) return 0;
                    visited[i-j]=1;
                }

            }

            now = a[y][i];
            b=0;
            continue;
        }
    }

    return 1;
}



int solve_col(int x){
    fill(&visited[0], &visited[0]+104, 0);
    int now = a[0][x], b=0;
    for(int i=1; i<n; i++){
        b++;
        if(now == a[i][x]){
            continue;
        }
        else{
            if(abs(now-a[i][x]) != 1) {
                return 0; 
            }

            if(now>a[i][x]){//아래로 내려갈때
                if(i>n-1) return 0; // 끝단에 놓을 수 없을때
                for(int j=1; j<l; j++){ // 밑에 발판을 놓을 수 있을 만큼 깔려있는지
                    if(a[i][x]==a[i+j][x]) continue;
                    return 0;
                }
                for(int j=0; j<l; j++){
                    visited[i+j] = 1;
                }
            }
            else if(now<a[i][x]){ // 위로 올라갈때
                if(b<l) return 0;
                for(int j=1; j<=l; j++){
                    if(visited[i-j]) return 0;
                    visited[i-j]=1;
                }

            }

            now = a[i][x];
            b=0;
            continue;
        }
    }

    return 1;
}

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        cnt += solve_row(i);
    }
    for(int i=0; i<n; i++){
        cnt += solve_col(i);
    }

    cout<<cnt<<'\n';
    return 0;
}