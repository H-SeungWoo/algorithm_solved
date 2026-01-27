#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k, a,b;
ll c;
vector<ll> tree, v;

void update(int idx, ll value){
    while(idx<tree.size()){
        tree[idx] += value;
        idx += idx & -idx;
    }
}

ll sum(int idx){
    ll ret = 0;
    while(idx>0){
        ret += tree[idx];
        idx -= idx&-idx;
    }
    return ret;
}

ll rangeQuery(int left, int right){
    return sum(right) - sum(left-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    v.resize(n+1);
    tree.resize(n+1);

    for(int i=1; i<=n; i++){
        cin>>v[i];
        update(i, v[i]);
    }

    for(int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if(a==1){
            ll diff = c-v[b];
            update(b,diff);
            v[b]= c;
        }
        else if (a==2){
            cout<<rangeQuery(b,c)<<'\n';
        }
    }

    return 0;
}