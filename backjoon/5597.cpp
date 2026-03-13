#include<bits/stdc++.h>
using namespace std;

bool a[31];

int main(){

    for(int i=0; i<28; i++){
        int n;
        cin>>n;
        a[n] = 1;
    }

    for(int i=1; i<=30; i++){
        if(!a[i]) cout<<i<<'\n'; 
    }

    return 0;
}