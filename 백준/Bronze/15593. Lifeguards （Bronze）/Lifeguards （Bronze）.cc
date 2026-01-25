#include<bits/stdc++.h>

using namespace std;

int n, ret;
vector<pair<int,int>> times;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int from=0, to=0;
        cin>>from>>to;
        times.push_back({from,to});
    }

    sort(times.begin(), times.end());
    
    for(int i=0; i<n; i++){
        int cnt =0, from=times[0].first, to=times[0].second;
        if(i==0){
            from=times[1].first, 
            to=times[1].second;
        }

        for(int j=0; j<n; j++){
            if(j==i) continue;
            if(i==0&&j==1) continue;
            
            // indivisual
            if(to<times[j].first){
                cnt += to - from;
                from=times[j].first;
                to = times[j].second;
            }

            // continuity
            else if(times[j].first <= to && times[j].second >= to){
                to=times[j].second;
            }
        }
        cnt += to - from;
        ret = max(cnt,ret);
    }

    cout<<ret<<'\n';
    return 0;
}