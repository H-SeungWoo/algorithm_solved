#include<bits/stdc++.h>

using namespace std;

int n, scores[304], dp[304][3], mx=0;

int solve(int here, int cnt){
    if(cnt>2) return -1e9;
    if(here<1) return 0;

    int & ret = dp[here][cnt];
    if(ret) return ret;

    if(cnt == 1){ // 연속 1계단인경우
        ret = max(solve(here-1,cnt+1),solve(here-2,1)) + scores[here];
    }
    else{ // 연속 2계단인 경우 무조건 두계단 뛰어야됨.
        ret = solve(here-2, 1)+scores[here];
    }

    return ret;

}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>scores[i];
    }

    mx = max(solve(n,1),solve(n,2));
    cout<<mx<<'\n';

    return 0;
}


//

// 1 2 3
//dp[3] = solve(1), solve(2)
// dp[1] = scores[1]
// dp[2] = solve(0), solve(1)