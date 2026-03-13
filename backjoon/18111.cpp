#include<bits/stdc++.h>
using namespace std;

int n,m,b,a[504][504] ,cnt[257], mx=-1, mn=257, ans_t= 1e9, ans_h=-1;

int solve(int x, int inven){
    int ret = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // x=5
            // 2 5 -> -3
            // 7 5 -> 2
            int diff = a[i][j]-x;
            inven += diff;
            if(diff>0) ret += 2 * diff;
            else if(diff<0) ret += -diff;
        }
    }

    //개수가 x로 갈 수 있는지 검사
    if(inven>=0) return ret;
    else return 1e9;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            cnt[a[i][j]]++;
            mx = max(a[i][j], mx);
            mn = min(a[i][j], mn);
        }
    }

    //목표치 완탐
    for(int i=mn; i<=mx; i++){
        int t = solve(i,b);
        if(ans_t >= t){
            ans_t = t;
            ans_h = i;
        }
    }

    cout<< ans_t << ' ' << ans_h<<'\n';

}