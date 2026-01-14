#include<bits/stdc++.h>

using namespace std;

const int INF =123456789;
int n, dp[1002];

int main(){

    cin>>n;

    memset(dp, -1, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) %10007;
    }
    cout<<dp[n]<<'\n';
    return 0;
}