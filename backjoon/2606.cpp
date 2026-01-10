#include<bits/stdc++.h>

using namespace std;

int n, m, a, b, ret, visited[101];
vector<int> com[101];

void findVirus(int here){
    visited[here] = 1;
    for(int next: com[here]){
        if(visited[next]) continue;
        ret++;
        findVirus(next);
    }
    
    return;
}

int main(){
    cin>>n>>m;

    while(m--){
        cin>> a>>b;
        com[a].push_back(b);
        com[b].push_back(a);
    }

    findVirus(1);

    cout<<ret<<'\n';
    return 0;
}