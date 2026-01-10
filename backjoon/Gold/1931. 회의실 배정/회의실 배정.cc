#include<bits/stdc++.h>

using namespace std;

int n, cnt, startTime, endTime;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        if(endTime <= v[i].second){
            cnt++;
            endTime = v[i].first;
        }
    }

    cout<<cnt<<'\n';
    return 0;
}