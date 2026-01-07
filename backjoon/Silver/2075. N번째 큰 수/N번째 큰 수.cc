#include<bits/stdc++.h>

using namespace std;

int n, a;
priority_queue<int,vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n*n; i++){
        cin>>a;
        pq.push(a);
        if(pq.size()>n){
            pq.pop();
        }
    }

    cout<<pq.top()<<'\n';
    return 0;
}