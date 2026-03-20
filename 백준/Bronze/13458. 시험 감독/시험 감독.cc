#include<bits/stdc++.h>
using namespace std;

int n, b, c;
long long ans;
vector<int> a;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int temp=0;
        cin>>temp;
        a.push_back(temp);
    }
    cin>>b>>c;

    for(int i=0; i<n; i++){
        a[i] -= b;
        ans++;

        if(a[i]>0){
            ans += a[i]/c;
            if(a[i]%c) ans++;
        }
    }

    cout<<ans<<'\n';
    return 0;
}