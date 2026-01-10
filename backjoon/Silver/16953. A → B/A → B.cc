#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a, b, cnt;
bool impos = false;

int main(){
    cin>>a>>b;

    while(b>a){
        if(b%10 == 1) {b/=10; cnt++;}
        else if (b%2==0) {b /=2; cnt++;}
        else impos = true;

        if(impos) break;
    }

    if(a!=b) impos=true;

    if(impos) cout<<-1<<'\n';
    else cout<<cnt+1<<'\n';

    return 0;
}