#include<bits/stdc++.h>

using namespace std;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

string s;
int n, a[30][30], visited[30][30], cnt=0;
vector<int> v;

int dfs(int y, int x, int c){
    visited[y][x] = c;
    int ret = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(visited[ny][nx]!=0) continue;
        if(a[ny][nx]==0) continue;

        ret += dfs(ny, nx, c);
    }

    return ret;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            a[i][j] = s[j]-'0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]==1 && visited[i][j]==0){
                cnt++;
                v.push_back(dfs(i,j,cnt));
            }
        }
    }

    cout<<cnt<<'\n';
    sort(v.begin(),v.end());
        for(int i: v){
        cout<<i<<'\n';
    }
    return 0;
}