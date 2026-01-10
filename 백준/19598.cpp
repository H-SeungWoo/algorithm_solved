#include<bits/stdc++.h>

using namespace std;

int from, to, n, ret = 0;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i=0; i<n; i++){
        cin >> from >> to;
        v.push_back({from, to});
    }

    sort(v.begin(),v.end());

    // 끝나는 시간 pq에 저장. 만약에 다음 회의 시작시간이 끝나는 시간보다 느리면 회의실 반납.
    // 체크 후, 회의실 배정. 중간에 최대 사용량이 될 수도 있으니 매 회의때마다 체크해주기.

    pq.push({v[0].second});
    for(int i=1; i<n; i++){
        if(v[i].first >= pq.top()) pq.pop();
        pq.push(v[i].second);
        ret = max(ret, (int)pq.size());
    }

    cout<<ret<<'\n';
    return 0;
}