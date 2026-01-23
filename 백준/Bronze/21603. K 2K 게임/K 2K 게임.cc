#include<bits/stdc++.h>

using namespace std;

int n, k, num1, num2, cnt;
vector<int> v;

int main(){

    cin>>n>>k;

    num1 = k%10;
    num2 = num1*2;

    for(int i=1; i<=n; i++){
        if(i%10==num1 || i%10==num2) continue;
        cnt++;
        v.push_back(i);
    }

    cout<< cnt<<'\n';

    for(int i: v){
        cout<<i<<' ';
    }

    cout<<'\n';
    return 0;

}