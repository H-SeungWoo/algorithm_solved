#include<bits/stdc++.h>

using namespace std;

int n, x, a[100004], cnt, l,r,k;

int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>x;

    sort(a,a+n);
    r=n-1;

    while(l<r){
        k=a[l]+a[r];
        if(k==x){
            cnt++;
            l++;
        }
        else{
            if(k<x) l++;
            else r--;
        }
    }

    cout<<cnt<<'\n';
    return 0;

}