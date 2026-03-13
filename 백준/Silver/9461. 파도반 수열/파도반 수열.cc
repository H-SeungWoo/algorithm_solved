#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int t, n;
ll p[104];

int main(){

    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    p[6] = 3;
    p[7] = 4;
    p[8] = 5;
    p[9] = 7;
    p[10] = 9;

    for(int i=11; i<=100; i++){
        p[i] = p[i-1] + p[i-5];
    }

    cin>>t;
    while(t--){
        cin>>n;
        cout<<p[n]<<'\n';
    }

    return 0;
}