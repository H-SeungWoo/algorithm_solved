#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, k, a, b, ret;

bool cmp(pair<int,int> a, pair<int,int>b){
    if(a.first==b.first) return a.second > b.second;
    return a.first>b.first;
}

int main(){
    
    cin>>n>>k;
    vector<pair<ll,ll>>jems(n);
    vector<ll>c(k);
    priority_queue<ll> pq;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        jems[i] = {a,b};
    }
    
    for(int i=0; i<k; i++){
        cin>>c[i];
    }
    
    
    // 용량이 적은 가방에 최대의 가격인걸 놓아야지.
    // 용량이 작은 것들끼리부터 비교 시작. -> 보석도 가방도 오름차순 정렬
    // 현재 i+1번째 가방에 보석이 들어갈 수 있는지 비교, 최대값인지 비교. 

    sort(jems.begin(), jems.end());
    sort(c.begin(), c.end());

    int j=0;
    for(int i=0; i<k; i++){
        while(j < n && jems[j].first <= c[i]) pq.push(jems[j++].second);
        if(pq.size()){
            ret += pq.top(); pq.pop();
        }
    }

    cout<<ret<<'\n';
    return 0;
}

// 99 65 23
// 2  1  5
// 2  10