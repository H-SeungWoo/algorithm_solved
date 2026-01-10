#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6;
int n, dp[maxN+4];

// int solve(int n, int cnt){
//     if(n==1 && dp[1]>cnt){
//         dp[1] = cnt;
//         return dp[1];
//     }
    
//     int &ret = dp[n];
//     if(ret <= cnt) return ret;

//     ret = solve(n-1, cnt+1);
//     if(n%3==0) ret = min(solve(n/3, cnt+1), ret);
//     if(n%2==0) ret = min(solve(n/2, cnt+1), ret);

//     return ret;
// }

int main(){
    cin>>n;
    fill(dp, dp+maxN, maxN+1);


    dp[1] = 0; // 1
    dp[2] = 1; // 2
    dp[3] = 1; // 3
    for(int i=4; i<=n; i++){
        if(i%2==0) dp[i] = dp[i/2]+1;
        if(i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
        dp[i] = min(dp[i], dp[i-1]+1);
    }

    cout <<dp[n]<<'\n';
    //cout << solve(n, 0) <<'\n';
    return 0;

}