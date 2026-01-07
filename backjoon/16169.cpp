#include<bits/stdc++.h>

using namespace std;

const int INF = 123456789;
struct Computer{
    int num;
    int level;
    int speed;

    Computer(int x, int y, int z): num(x), level(y), speed(z){}
}; 

Computer* computers[101];
int n, a, b, ret, dp[101];
vector<int> nodes[101];

int send(int i, int j){
    return (i-j)*(i-j);
}

int solve(int level){
    if(level>n) return 0;

    int& ret = dp[level];
    if(ret != INF) return ret;

    for(int node: nodes[level]){
        ret = min(ret, computers[node].speed + send(node, solve(level+1)));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        computers[i] = new Computer(i,a,b);
        nodes[a].push_back(i);
    }


    fill(dp, dp+101, INF);


}