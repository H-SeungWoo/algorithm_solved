#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, mx, ans=0;
vector<ll> woods;

bool solve(ll h){
    ll sum=0;
    for(int i=0; i<n; i++){
        if(woods[i]>h) sum+=woods[i]-h;
    }

    return sum>=m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        ll temp;
        cin>>temp;
        woods.push_back(temp);
        mx = max(temp, mx);
    }

    ll l=0, r=mx;
    while(l<=r){
        ll mid = (l+r)/2;
        if(solve(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }

    }

    cout<<ans<<'\n';
    return 0;

}