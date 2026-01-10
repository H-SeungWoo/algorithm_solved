#include<bits/stdc++.h>

using namespace std;

int n, m, a[1025][1025], psum[1024][1024], ret;
int test[100000][4];


int main(){

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cin>>test[i][0]>>test[i][1]>>test[i][2]>>test[i][3];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] 
            -psum[i-1][j-1] +a[i][j];
        }
    }

    // cout<<'\n';
    // for(int i=1; i<=n;i++){
    //     for(int j=1; j<=n; j++){
    //         cout << psum[i][j] <<' ';
    //     }
    //     cout <<'\n';
    // }

    for(int i=0; i<m; i++){
        ret =0;
        int x1=test[i][1], x2=test[i][3], y1=test[i][0], y2=test[i][2];

        ret = psum[y2][x2] - psum[y1-1][x2] - psum[y2][x1-1] + psum[y1-1][x1-1];

        cout<<ret<<'\n';
        // if(y1 == y2){
        //     cout<< psum[y2][x2] - psum[y1][x1] <<'\n';
        // }
        // else {
        //     cout << psum[y2][x2] <<'-'<< psum[y1][x1] << '\n';
        // }
    }

}