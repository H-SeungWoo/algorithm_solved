#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
long long dp[31][31];

ll solve(int pill, int half){
    if(pill==0 && half==0) return 1;
    ll &ret = dp[pill][half];
    if(ret) return ret;
    if(pill>0) ret += solve(pill-1,half+1);
    if(half>0) ret += solve(pill, half-1);
    return ret;
}

int main(){


    while(true){
        cin>>n; if(n==0) break;
        cout<<solve(n,0)<<'\n';
    }
    cout<<'\n';
    return 0;
}

