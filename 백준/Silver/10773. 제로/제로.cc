#include<bits/stdc++.h>

using namespace std;

int n, sum;
vector<int> v;

int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        int temp =0;
        cin>>temp;
        if(temp==0) v.pop_back();
        else v.push_back(temp);
    }

    for(int i: v){
        sum+= i;
    }

    cout<<sum<<'\n';
    return 0;
}