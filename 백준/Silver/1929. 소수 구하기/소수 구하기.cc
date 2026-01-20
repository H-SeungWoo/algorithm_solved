#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;

    vector<bool> isPrime(m+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=m; i++){
        if(isPrime[i]){
            for(int j = i*i; j<=m; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=n; i<=m; i++){
        if(isPrime[i]){
            cout<<i<<'\n';
        }
    }

    return 0;
}