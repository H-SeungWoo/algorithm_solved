#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main(){
    cin>>t;
    
    while(t--){
        int cnt=0, priority =0, mx_pri=0;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        cin>>n>>m;

        for(int i=0; i<n; i++){
            cin>>priority;
            mx_pri = max(mx_pri, priority);
            q.push({priority, i});
            pq.push(priority);
        }

        while(!q.empty()){
            pair<int,int> docu = q.front();
            if(docu.first != mx_pri){  
                q.push(docu);
                q.pop();
            }

            else{
                cnt++;
                if(docu.second == m){
                    break;
                }

                else{
                    q.pop();
                    pq.pop();
                    mx_pri = pq.top();
                }
            }
        }
        
        cout<<cnt<<'\n';

    }
}