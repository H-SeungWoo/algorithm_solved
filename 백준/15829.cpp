#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
string str;
ll ret=0, M=1234567891, r=1;

int main(){

    cin>>n>>str;

    for(int i=0; i<n; i++){
        int a = str[i]-'a'+1;
        ret = (ret + (a * r))% M;
        r = (r*31) % M;
    }

    cout<<ret<<'\n';
    return 0;
}