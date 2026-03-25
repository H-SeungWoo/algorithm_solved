#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int n, m, start_x, start_y, k, test_map[25][25], cmd[1004];

struct Dice{
    int q, e, w,a,s,d;   
}dice;

void rollEast(Dice& _dice){
    int temp = _dice.e;
    _dice.e= _dice.d;
    _dice.d= _dice.q;
    _dice.q= _dice.a;
    _dice.a= temp;
}

void rollWest(Dice& _dice){
    int temp= _dice.e;
    _dice.e= _dice.a;
    _dice.a= _dice.q;
    _dice.q= _dice.d;
    _dice.d= temp;
}

void rollNorth(Dice& _dice){
    int temp = _dice.e;
    _dice.e= _dice.w;
    _dice.w= _dice.q;
    _dice.q= _dice.s;
    _dice.s= temp;
}

void rollSouth(Dice& _dice){
    int temp = _dice.e;
    _dice.e= _dice.s;
    _dice.s= _dice.q;
    _dice.q= _dice.w;
    _dice.w= temp;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>start_y>>start_x>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>test_map[i][j];
        }
    }

    for(int i=0; i<k; i++){
        cin>>cmd[i];
    }

    int x=start_x, y=start_y;

    for(int j=0; j<k; j++){
        int i = cmd[j];
        int ny = y+dy[i-1];
        int nx = x+dx[i-1];

        if(ny<0 || nx<0||ny>=n||nx>=m) continue;
        y=ny; x=nx;
        // 주사위 회전
        if(i==1){
            rollEast(dice);
        }
        else if(i==2){
            rollWest(dice);
        }
        else if(i==3){
            rollNorth(dice);
        }
        else{
            rollSouth(dice);
        }

        if(test_map[y][x] == 0){
            test_map[y][x] = dice.e;
        }
        else{
            dice.e=test_map[y][x];
            test_map[y][x] = 0;
        }

        cout<<dice.q<<'\n';
    }

    return 0;

}