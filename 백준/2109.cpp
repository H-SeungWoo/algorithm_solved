#include <bits/stdc++.h>

using namespace std;

int n, day, ret;
vector<pair<int,int>> a;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int p, d;
        cin>>p>>d;
        a.push_back({d,p});                
    }
    
    sort(a.begin(),a.end());

    int idx =0;
    while(idx<n){
        while(idx<n&&a[idx].first<=day) {
            pq.push(a[idx++].second);
        }
        while(pq.size()>day) pq.pop();
        day++;
    }

    while(pq.size()){
        ret += pq.top(); pq.pop();
    }        

    cout << ret <<'\n';

    return 0;
}

// 최소힙으로 -> 제일 낮은거를 빼버려. 그 날짜 개수만큼 남을때까지.  