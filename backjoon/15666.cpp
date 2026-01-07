#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v, picked;

void printV(){
    for(int i=0; i<m; i++){
        cout<<picked[i]<<' ';
    }
    cout<<'\n';
}

void dfs(int start){
    if((int)picked.size() == m){
        printV();
        return;
    }

    for(int i=start; i<(int)v.size(); i++){
        picked.push_back(v[i]);
        dfs(i);
        picked.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    dfs(0);

    return 0;
}