#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[1004];

int main(){
    cin>>n;
    
    a[1] = 1;
    a[2] = 3;

    for(int i=3; i<=n; i++){
        a[i] = (a[i-1] + a[i-2]*2)%10007;
    }

    cout<<a[n]<<'\n';
    return 0;   
}