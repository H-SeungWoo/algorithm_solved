#include<bits/stdc++.h>

using namespace std;

int n, a[300001], sum, cnt, m;

int main(){
    cin>>n;

    if(n==0){
        cout<<0<<'\n';
        return 0;
    }

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);

    m = (int)floor(n*0.15+0.5);


    for(int i=m; i<n-m; i++){
        sum += a[i];
    }

    cout<<(int)floor(sum/float(n-m*2)+0.5)<<'\n';
    return 0;
}