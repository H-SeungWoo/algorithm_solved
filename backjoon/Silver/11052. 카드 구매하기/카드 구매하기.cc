#include<bits/stdc++.h>
using namespace std;

int n, p[1004], dp[1004], ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(dp,dp+1004, 0);

    cin>>n;
    for(int i=1; i<=n; i++){

        cin>>p[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], p[j]+dp[i-j]);
        }
    }

    cout << dp[n] <<'\n';
    return 0;
}