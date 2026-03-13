#include<bits/stdc++.h>

using namespace std;

int n, t, a[51], b, ret;

int main(){

    cin>>n>>t;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        b+=a[i];
        if(b>t) break;
        ret++;
    }

    cout<<ret<<'\n';
}