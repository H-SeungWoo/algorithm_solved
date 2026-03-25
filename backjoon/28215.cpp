#include<bits/stdc++.h>
using namespace std;

// 대피소 3개 선택
// 거리계산
// 거리 최대값 비교
// 정답 비교 

int n,k, ans=1e9;
vector<pair<int,int>> house;
vector<int> v1;

int solve(vector<int> v){
    vector<pair<int,int>> shleter;
    int mxDist = 0;
    for(int i: v){
        shleter.push_back(house[i]);
    }

    for(int i=0; i<n; i++){
        int mn = 1e9;
        for(int j=0; j<k; j++){
            int dist = abs(shleter[j].first-house[i].first) + abs(shleter[j].second-house[i].second);
            if(dist == 0) dist=-1;
            mn = min(mn,dist);
        }
        if(mn == -1) continue;

        mxDist = max(mn,mxDist);
    }    

    return mxDist;
}

void combi(int start, vector<int> v){
    if(v.size()==k){
        //거리 계산
        ans = min(ans, solve(v));
        return;
    }

    for(int i=start+1; i<n; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        house.push_back({temp1,temp2});
    }

    combi(-1, v1);
    cout<<ans<<'\n';
    return 0;
}