#include<bits/stdc++.h>

using namespace std;

const int INF = 1234567891;
int n,m, video[100001], sum, ret = INF, mx=0;

bool search(int bluelaysize){
    int cnt = 1,  bluelaysum = 0;
    for(int i=0; i<n; i++){
        if(bluelaysize<video[i]) return false;

        if(bluelaysum+ video[i] > bluelaysize){
            bluelaysum = 0;
            cnt++;
        }
        bluelaysum += video[i];
    }


    return cnt <= m;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>video[i];
        sum+=video[i];
        mx = max(mx,video[i]);
    }

    int left = mx, right=sum, mid=0;

    while(left<=right){
        mid = (left+right) / 2;

        if(search(mid)){
            ret = min(ret, mid);
            right = mid-1;
        }
        else left = mid +1;
    }

    cout << ret<< '\n';
}