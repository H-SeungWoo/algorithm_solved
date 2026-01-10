#include<bits/stdc++.h>

using namespace std;

int dx[3] = {0,1,2};
int n, stage[100001][3];
int dpMax[100001][3], dpMin[100001][3];

int solveMax(int level, int idx){
    if(level >= n) return 0;

    int& ret = dpMax[level][idx];
    if(ret != -1) return ret;

    int nowScore = stage[level][idx];
    ret = solveMax(level+1, idx) + nowScore;
    for(int nx: dx){
        if(idx==nx || idx+nx==2) continue;
        ret = max(ret, solveMax(level+1, nx)+nowScore);
    }

    return ret;
}

int solveMin(int level, int idx){
    if(level >= n) return 0;

    int& ret = dpMin[level][idx];
    if(ret != -1) return ret;

    int nowScore = stage[level][idx];
    ret = solveMin(level+1, idx) + nowScore;
    for(int nx: dx){
        if(idx==nx || idx+nx==2) continue;
        ret = min(ret, solveMin(level+1, nx)+nowScore);
    }

    return ret;
}


int main(){
    
    memset(dpMax, -1, sizeof(dpMax));
    memset(dpMin, -1, sizeof(dpMin));

    cin>>n;
    for(int i=0; i<n; i++){
       cin>>stage[i][0]>>stage[i][1]>>stage[i][2];
    }

    cout << max(solveMax(0, 0), max(solveMax(0, 1), solveMax(0,2))) << '\n';
    cout << min(solveMin(0, 0), min(solveMin(0, 1), solveMin(0,2))) << '\n';
    return 0;
}