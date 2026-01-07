#include<bits/stdc++.h>

using namespace std;

int n, a[128][128], retB, retW;

void solve(int y, int x, int n){

    int firstNum = a[y][x];
    for(int i=y; i<y+n; i++){
        for(int j=x; j<x+n; j++){
            if(a[i][j] != firstNum){
                solve(y,     x,     n/2);
                solve(y,     x+n/2, n/2);
                solve(y+n/2, x,     n/2);
                solve(y+n/2, x+n/2, n/2);
                return;
            }
        }
    }

    if(firstNum==1) retB++;
    else retW++;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    solve(0,0,n);
    cout<<retW<<'\n';
    cout<<retB<<'\n';

    return 0;
}