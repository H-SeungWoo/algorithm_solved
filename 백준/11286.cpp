#include<bits/stdc++.h>
using namespace std;

// 우선순위큐에, 부호정보를 따로 넣는다.

int n;
priority_queue<pair<int,bool>, vector<pair<int,bool>>, greater<pair<int,bool>>> pq;

int main(){
    cin>>n;
    while(n--){
        int x=0;
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<0<<'\n';
            else{
                if(pq.top().second==false){

                    cout<<-pq.top().first<<'\n';
                }
                else{
                    cout<<pq.top().first<<'\n';
                }
                pq.pop();
                
            }
        }
        else{
            if(x<0){
                pq.push({-x,0});
            }
            else{
                pq.push({x,1});
            }

        }
    }
}