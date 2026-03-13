#include<bits/stdc++.h>
using namespace std;

int n, x, sum;
int a[2004];

int main(){
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i] %= x;
    }

    for(int i: a){
        sum += i;
    }

    if(sum%x==0) cout<<1<<'\n';
    else cout<<0<<'\n';

    return 0;
}