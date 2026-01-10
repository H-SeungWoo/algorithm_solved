#include<bits/stdc++.h>

using namespace std;

int n, ret;
vector<pair<int,int>> a;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int temp1=0, temp2=0;
        cin>>temp1>>temp2;
        a.push_back({temp1, temp2});
    }

    sort(a.begin(),a.end());

    for(int i=0; i<n; i++){
        pq.push(a[i].second);
        if(pq.size()>a[i].first){
            pq.pop();
        }
    }

    while(pq.size()){
        ret+=pq.top();
        pq.pop();
    }
    cout<<ret<<'\n';
    return 0;
}