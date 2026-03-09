#include<bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string, string> mp;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> n>> m;

    for(int i=0; i<n; i++){
        string temp1, temp2;
        cin>>temp1>>temp2;
        mp[temp1]=temp2;
    }

    string test;
    while(m--){
        cin>>test;
        cout<<mp[test]<<'\n';
    }

    return 0;
}