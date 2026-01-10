#include <bits/stdc++.h>

using namespace std;

int a[104][104], n, temp1, temp2, cnt;
vector<pair<int,int>> v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp1>>temp2;
        v.push_back({temp2,temp1});
    }

    for(auto pii: v){
        for(int i=pii.second; i<pii.second+10; i++){
            for(int j=pii.first; j<pii.first+10; j++){
                a[i][j] = 1;
            }
        }
    }

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(a[i][j]) cnt++;
        }
    }

    cout << cnt<<'\n';

    return 0;
}