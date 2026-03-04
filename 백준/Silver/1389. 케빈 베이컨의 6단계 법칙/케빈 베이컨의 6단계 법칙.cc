#include<bits/stdc++.h>
using namespace std;

int n,m,sum;
vector<int> a[104];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        a[temp1].push_back(temp2);
        a[temp2].push_back(temp1);
    }

    int ans_person = 1;
    int ans_sum = 1e9;

    for(int i=1; i<=n; i++){
        vector<int> dist(n+1, -1);
        queue<int> q;
        
        dist[i] = 0;
        q.push(i);

        while(q.size()){
            int now = q.front();
            q.pop();
            for(int next: a[now]){
                if(dist[next] != -1) continue;
                q.push(next);
                dist[next] = dist[now] +1;
            }
        }

        int sum = 0;
        for(int j=1; j<=n; j++) sum +=dist[j];

        if(sum<ans_sum){
            ans_sum = sum;
            ans_person = i;
        }
    }

    cout<<ans_person<<'\n';
    return 0;
}