#include<bits/stdc++.h>

using namespace std;

int n, price[1000][3], dp[1000][3], mn;

int solve(int level, int color){
    if(level>=n) return 0;

    int& ret = dp[level][color];
    if(ret!=0) return ret;
    
    // 현재 비용에 레벨이 +1의 다른 color의 비용을 더한다.

    ret = min(solve(level+1,(color+1)%3), solve(level+1, (color+2)%3)) + price[level][color];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>price[i][0]>>price[i][1]>>price[i][2];
    }

    memset(dp, 0, sizeof(dp));
    
    mn = min(solve(0,0),min(solve(0,1),solve(0,2)));
    cout << mn <<'\n';

    return 0;
}