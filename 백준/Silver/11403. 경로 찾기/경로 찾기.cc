#include<bits/stdc++.h>
using namespace std;

int n, visited[104];
vector<int> v[104];

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0;
            cin>>temp;
            if(temp==0) continue;
            v[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++)
    {
        fill(visited, visited+104, 0);
        queue<int> q;
        
        q.push(i);

        while(q.size()){
            int x = q.front();
            q.pop();

            for(int next: v[x]){
                if(visited[next]) continue;
                visited[next] = 1;
                q.push(next);
            }

        }

        for(int j=0; j<n; j++){
            cout<<visited[j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}