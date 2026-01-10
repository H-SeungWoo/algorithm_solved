#include<bits/stdc++.h>

using namespace std;

int n, a[20][20], dp[20][20];

bool moveright(int y, int x){
    if((x+1==n-1)||(a[y][x+1]==1)) return false;
    return true;
}

int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }


}