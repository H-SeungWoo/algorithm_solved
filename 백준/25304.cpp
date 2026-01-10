#include<bits/stdc++.h>

using namespace std;

int total, n, sum, a, b;

int main(){
    cin>>total>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        sum+=a*b;
    }

    if(total==sum) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';

    return 0;
    
}

