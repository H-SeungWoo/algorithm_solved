#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=0;
    while(cin>>n){
        if(n==0) break;

        if(n>1000000 && n<=5000000) n = n*0.9;
        else if (n>5000000) n = n*0.8;

        cout<<n<<'\n';
    }

    return 0;
}