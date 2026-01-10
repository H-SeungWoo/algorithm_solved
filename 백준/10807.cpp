#include<bits/stdc++.h>

using namespace std;

int n, a[101], v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>v;

    cout<< count(a, a+n,v)<<'\n';
    return 0;
}