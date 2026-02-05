#include<bits/stdc++.h>
using namespace std;

int a[6], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    a[1] = 1;

    for(int i=2; i<=5; i++){
        a[i] = a[i-1] * i;
    }

    while(cin>>n){
        if(n==0) break;

        int ret=0;
        int i=1;
        while(n!=0){
            ret += (n%10)*a[i++];
            n /= 10;
        }

        cout<<ret<<'\n';
    }

    return 0;
}