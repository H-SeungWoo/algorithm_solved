#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
int n, a[20][20];
ll dp[20][20][20], mn=INF;

ll solve(int start, int here, int visitedCnt){
    if(visitedCnt>=n && start==here) return 0;
    
    ll& ret = dp[start][here][visitedCnt];
    if(ret!=INF) return ret; 

    for(int i=0; i<n; i++){
        ll there = a[start][i];
        if(there==0) continue;
        cout<<there<<'\n';
        ret += min(ret, solve(start, i, visitedCnt+1))+there;
    }

    return ret;
}


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    fill(&dp[0][0][0], &dp[0][0][0] +20*20*20, INF);

    for(int i=0; i<n; i++){
        fill(visited, visited+16, 0);
        mn = min( mn, solve(i,i,0));
    }

    cout << mn <<'\n';
    return 0;
}