#include<bits/stdc++.h>

using namespace std;

int t, n, dp[12];

int main(){

    cin >>t;
    dp[0] = 1;
    for(int j=1; j<=11; j++){
        for(int i=1; i<=3; i++){
            if(j-i>=0) dp[j] += dp[j-i];
        }
    }

    while(t--){
        cin>>n;
        cout<<dp[n]<<'\n';
    }

    return 0;    
}