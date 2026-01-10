#include<bits/stdc++.h>

using namespace std;

int t, a, a1, a2;
pair<int,int> ret[41];

int main(){
    cin>>t;
    ret[0] = {1,0};
    ret[1] = {0,1};
    for(int i=2; i<41; i++){
        ret[i] = {ret[i-2].first+ret[i-1].first,ret[i-2].second+ret[i-1].second};
    }

    while(t--){
        cin>>a;
        cout<< ret[a].first << ' ' << ret[a].second <<'\n';

    }
    
    return 0;   
}