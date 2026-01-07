#include<bits/stdc++.h>

using namespace std;

int hour, minute, cook, e_h, e_m;

int main(){
    cin>>hour>>minute>>cook;

    e_m = (minute+cook)%60;
    e_h = hour+(minute+cook)/60;
    e_h %= 24;

    cout << e_h <<" "<< e_m<<'\n';
    return 0;

    
}