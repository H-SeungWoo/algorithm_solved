#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, r, c;
ll ans;

ll solve(ll num, int length, int i, int j){
    if(length == 1) {
        return num;
    }

    ll max_num = length*length;
    //1사분면
    if(i<length/2 && j<length/2){
        return solve(num,length/2, i,j);
    }
    //2사분면
    else if(i<length/2 && j>=length/2){
        return solve(num+(max_num/4)*1, length/2, i, j-length/2);
    }
    //3사분면
    else if(i>=length/2 && j<length/2){
        return solve(num+(max_num/4)*2, length/2, i-length/2, j);
    }
    //4사분면
    else if(i>=length/2 && j>=length/2){
        return solve(num+(max_num/4)*3, length/2, i-length/2, j-length/2);
    }

    return -1;
}

int main(){
    cin>>n>>r>>c;

    int len = 1;
    for(int i=0; i<n; i++)
    {
        len *= 2;
    }

    cout<<solve(0, len, r, c)<<'\n';
    return 0;
}