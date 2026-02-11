#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, dp[50002], ans;

int main(){
    cin>>n;
    
    fill(dp, dp+50002, INF);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=1; j*j<=i; j++)
        dp[i] = min(dp[i-j*j]+1, dp[i]);
    }

    cout<<dp[n]<<'\n';
    return 0;
}