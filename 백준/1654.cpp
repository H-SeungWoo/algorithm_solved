#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;
ll a[10004], mx_len, ans;

bool solve(ll x){
    ll cnt=0;
    for(int i=0; i<k; i++){
        cnt += a[i]/x;
    }

    return cnt>=n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>n;
    for(int i=0; i<k; i++){
        cin>>a[i];
        mx_len = max(mx_len, a[i]);
    }

    ll l = 1, r = mx_len;
    while(l<=r){
        ll mid = (l+r)/2;
        if(solve(mid)){
            ans = max(ans, mid);
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout<<ans<<'\n';
}