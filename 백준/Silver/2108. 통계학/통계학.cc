#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> v;


int main(){
    cin>>n;

    ll sum = 0;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        sum += temp;

    }

    sort(v.begin(), v.end());

    ll a = round((double)sum/n);
    ll b = v[n/2];

    int cnt[8004] = {0};
    for(int i: v){
        cnt[i+4000]++;
    }

    int mx_cnt =0;
    for(int i=0; i<=8000; i++){
        mx_cnt = max(mx_cnt, cnt[i]);
    }

    vector<int> v2;
    for(int i=0; i<=8000; i++) {
        if(cnt[i] == mx_cnt) v2.push_back(i-4000);
    }

    ll c = (v2.size()==1? v2[0] : v2[1]);

    ll d = v.back()-v.front();

    cout<<a<<'\n';
    cout<<b<<'\n';
    cout<<c<<'\n';
    cout<<d<<'\n';

    return 0;
}