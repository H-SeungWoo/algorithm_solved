#include<bits/stdc++.h>

using namespace std;

int n;


int main(){
    
    cin>>n;
    
    long long ans = 0;
    for(long long p = 5; p<=n; p*=5){
        ans += n/p;
    }

    cout<<ans<<'\n';
    return 0;
}