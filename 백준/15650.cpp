#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> temp;
void solve(int index, vector<int>& v){
    if(v.size()==k){
        for(int i: v){
            cout << i <<" ";
        }
            cout<<'\n';
            return;
    }

    for(int i=index+1; i<=n; i++){
        v.push_back(i);
        solve(i, v);
        v.pop_back();
    }
    return;
    
}

int main(){
    cin>>n>>k;

    solve(0,temp);
    return 0;

}