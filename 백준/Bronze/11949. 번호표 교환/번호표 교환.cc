#include<bits/stdc++.h>

using namespace std;

int n,m, a[104];

int main(){

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=1; i<=m; i++){
        for(int j=0; j<n-1; j++){
            if(a[j]%i>a[j+1]%i){
                swap(a[j],a[j+1]);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<'\n';
    }

    return 0;
}