#include<bits/stdc++.h>

using namespace std;

int x,cnt;
int main(){
    cin>>x;
    for(int i=0; i<7; i++){
        if(x&(1<<i)) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}