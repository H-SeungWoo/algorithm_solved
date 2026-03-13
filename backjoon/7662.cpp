#include<bits/stdc++.h>
using namespace std;

int t;
priority_queue<int>, vector<int>> min_pq;
priority_queue<int>, vector<int>, less<int>> max_pq;
map<int, int> mp;
vector<int> ret;
//

void solve(){
    int k=0;
    cin>>k;
    while(k--){
        char i;
        int n;
        cin>>i>>n;
        if(i=='I'){
            min_pq.push(n);
            max_pq.push(n);
            mp[n]++;
        }
        else{
            if(n==1){
                max_pq.pop();
            }
            else{
                min_pq.pop();
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
}