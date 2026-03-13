#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll d;
vector<pair<ll,ll>> present;

ll solve(){
    ll sum=0, ret=0, l=0;
    for(int r=0; r<n; r++){
        sum += present[r].second;
        
        while(present[r].first - present[l].first>=d){
            sum -= present[l].second;
            l++;
        }
        ret=max(sum,ret);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>d;
    for(int i=0; i<n; i++){
        int p, v;
        cin>>p>>v;
        present.push_back({p,v});
    }

    sort(present.begin(), present.end());

    cout<<solve()<<'\n';

}

// 1 2 3 4   10
// 5 7 9 10  50