#include<bits/stdc++.h>
using namespace std;

int n, dp[504][504];
vector<int> a[504];


int solve(int level, int here){
    if(level == n-1) return a[level][here];

    return a[level][here] + max(solve(level+1, here), solve(level+1, here+1));
}

int solve_dp(int level, int here){
    if(level==n-1) return a[level][here];

    int& ret = dp[level][here];
    if(ret !=-1) return ret;

    ret = a[level][here] + max(solve_dp(level+1, here), solve_dp(level+1, here+1));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            int temp=0;
            cin>>temp;
            a[i].push_back(temp);
        }
    }

    fill(&dp[0][0], &dp[0][0]+504*504, -1);

    //cout<<solve(0,0)<<'\n';
    cout<<solve_dp(0,0)<<'\n';
}