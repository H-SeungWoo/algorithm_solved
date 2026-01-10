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
int n, a, b, ret, dp[101], maxLevel;
vector<int> nodes[101];

int send(int i, int j){
    return (i-j)*(i-j);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        computers[i] = new Computer(i,a,b);
        nodes[a].push_back(i);

        maxLevel=max(maxLevel, a);
    }


    fill(dp, dp+101, 0);

    nodes[0].push_back(0);

    for(int i=1; i<=maxLevel; i++){
        for(int node: nodes[i]){
            for(int pre: nodes[i-1]){
                int sendtime = 0;
                if(i != 1) sendtime = send(node,pre);
                
                dp[node] = max(dp[node], dp[pre]+ computers[node]->speed + sendtime);
            }
        }        
    }
    
    for(int node: nodes[maxLevel]){
        ret = max(ret, dp[node]);
    }

    cout<<ret<<'\n';

}