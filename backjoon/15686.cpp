#include<bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
const int INF = 1e9;

int n, m, a[54][54], visited[54][54], ret = INF;
vector<pair<int,int>> homeList, chickenList;
// m개의 치킨집을 조합하는 로직
// 치킨 거리를 구하는 로직

int solve(int mask){
    int sum = 0;
    for(int i=0; i<homeList.size(); i++){
        int homeDist = INF;
        for(int j=0; j<chickenList.size(); j++){
            if(mask&(1<<j)){
                int y = abs(homeList[i].first - chickenList[j].first);
                int x = abs(homeList[i].second - chickenList[j].second);
                homeDist = min(homeDist, y+x);
            }
        }
        if(homeDist== INF) return INF;
        sum += homeDist;
    }
    return sum;
}

void combi(int mask, int depth, int cnt){

    if(cnt==m){
        ret = min(solve(mask), ret);
        return;
    }

    if(depth==chickenList.size()) return;


    combi(mask, depth+1, cnt);
    combi(mask|(1<<depth), depth+1, cnt+1);

}


int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j]==2) chickenList.push_back({i,j});
            if(a[i][j]==1) homeList.push_back({i,j});
        }
    }

    combi(0, 0, 0);
    cout << ret <<'\n';
    return 0;   
}