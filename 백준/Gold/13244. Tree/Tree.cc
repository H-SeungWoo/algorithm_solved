#include<bits/stdc++.h>

using namespace std;

int t,n,m, visited[1004];
vector<int> a[1004];


//visited된 개수를 센다. visited된 개수는 
int solve(int before, int here){
    int ret = 1;
    //cout<<"before: "<<before<<" -> here: "<<here<<'\n';
    visited[here]=1;
    for(int there: a[here]){
        if(there==before) continue;
        if(visited[there]) {
            //cout<<"worng node: " << here <<"->"<<there<<'\n';
            return -1000;}
    //cout<<"here: "<<here<<" -> there: "<<there<<'\n';
        ret += solve(here, there);
    }
    
    //cout<<"before: "<<before<<" -> here: "<<here<<" ret: "<<ret<<'\n';
    return ret;

    // 7-2-4-3
    //     | 
    //     5-6-1
}

int main(){
    cin>>t;
    while(t--){
        fill(visited,visited+1004,0);
        for(int i=0; i<1004; i++){
            a[i].clear();
        }
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int temp1=0,temp2=0;
            cin>>temp1>>temp2;
            a[temp1].push_back(temp2);
            a[temp2].push_back(temp1);
        }

        if(n==solve(0,1)) cout<<"tree"<<'\n';
        else cout<<"graph"<<'\n';
    }

    return 0;
}