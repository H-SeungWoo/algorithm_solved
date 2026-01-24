#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string a, b, ret;
int n, m, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>a>>b;

    n = (int)a.size() - 1;
    m = (int)b.size() - 1;

    while(n>= 0 || m>=0 || k){
        int sum = k;
        if(n>=0) sum += a[n--] - '0';
        if(m>=0) sum += b[m--] - '0';
        
        ret += ('0'+sum%10);
        k = sum/10;
    }

    reverse(ret.begin(), ret.end());
    cout << ret<<'\n';
    return 0;
}