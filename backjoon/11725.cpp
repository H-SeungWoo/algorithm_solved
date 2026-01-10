#include<bits/stdc++.h>

using namespace std;

int n, parent[100001], visited[100001];
vector<int> tree[100001];

void findParent(int here){
    visited[here]=1;
    for(int next: tree[here]){
        if(visited[next])continue;
        parent[next] = here;
        findParent(next);
    }

    return;
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        int temp1=0, temp2=0;
        cin>>temp1>>temp2;
        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }

    findParent(1);

    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }

    return 0;
}