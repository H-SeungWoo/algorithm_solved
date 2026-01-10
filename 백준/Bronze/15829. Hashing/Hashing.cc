#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
string str;
ll ret=0;

ll MyPow(int x, int k){
    ll ret=1;
    for(int i=1; i<=k; i++){
        ret *= x;
    }
    return ret;
}

int main(){

    cin>>n>>str;

    for(int i=0; i<n; i++){
        ret += (str[i]-'a'+1) * MyPow(31, i);
    }

    cout<<ret<<'\n';
    return 0;
}