#include<bits/stdc++.h>

using namespace std;

int n, a, b, delay, ret;
vector<pair<int, int>> v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    int realTime = v[0].first +v[0].second;
    for(int i=1; i<n; i++){
        realTime = max(realTime, v[i].first);
        realTime += v[i].second;
    }

    cout << realTime <<'\n';
}