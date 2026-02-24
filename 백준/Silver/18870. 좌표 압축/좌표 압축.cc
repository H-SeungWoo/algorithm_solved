#include<bits/stdc++.h>
using namespace std;

int n, a[1000004], b[1000004];
unordered_map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b,b+n);
    int end = unique(b,b+n) -b;
    for(int i=0; i<end; i++){
        mp[b[i]]=i;
    }

    for(int i=0; i<n; i++){
        cout<<mp[a[i]]<<' ';
    }
    cout<<'\n';
    return 0;

}