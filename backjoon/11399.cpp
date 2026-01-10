#include<bits/stdc++.h>

using namespace std;

int n, sum, ret;
vector<int> v;


int main(){

    cin>>n;
    for(int i=0; i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        sum+=v[i];
        ret += sum;
    }

    cout << ret <<'\n';
    return 0;
}