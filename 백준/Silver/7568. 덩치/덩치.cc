#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> ret;
vector<pair<int,int>> v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        v.push_back({temp1,temp2});
    }

    for(int i=0; i<n; i++){
        int rank = 1;
        for(int j=0; j<n; j++){
            if (i==j) continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second) rank++;
        }
        ret.push_back(rank);
    }

    for(int i: ret){
        cout << i <<' ';
    }
    cout<<'\n';
    return 0;
}