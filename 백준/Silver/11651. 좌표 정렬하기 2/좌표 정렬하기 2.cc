#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second < b.second;
    return a.first< b.first;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x=0,y=0;
        cin>>x>>y;
        v.push_back({y,x});
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<n; i++){
        cout<<v[i].second<<" "<<v[i].first<<'\n';
    }

    return 0;
}