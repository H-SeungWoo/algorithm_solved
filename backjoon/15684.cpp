#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n,m,h,ret=INF;
int a[34][14];

bool check(){
    for(int i=1; i<=n; i++){
        int x=i;
        for(int j=1; j<=h; j++){
            if(x<n && a[j][x]) x++;
            else if(x>1 && a[j][x-1]) x--;
        }
        if(x!=i) return false;
    }
    return true;
}

void solve(int here, int cnt){
    if(cnt>= 4 || cnt>= ret) return;
    if(check()){
        ret = min(cnt, ret); return;
    }
    for(int i=here; i<=n; i++){
        for(int j=1; j<=h; j++){
            if(a[j][i] || (a[j][i-1])|| (a[j][i+1])) continue;

            a[j][i] = 1;
            solve(i,cnt+1);
            a[j][i] = 0;
        }

    }
    return;
    
}


int main(){
    cin>>n>>m>>h;
    for(int i=0; i<m; i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        a[temp1][temp2] = 1;
    }

    solve(1,0);
    
    if(ret==INF) cout<<-1<<'\n';
    else cout<<ret<<'\n';

    return 0;    
}