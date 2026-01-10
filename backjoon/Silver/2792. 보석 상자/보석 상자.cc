#include<bits/stdc++.h>

using namespace std;

int n, m, a[300004], ans=1e9;

bool check(int num){
    int temp = 0;
    for(int i=0; i<m;i++){
        temp += a[i]/num;
        if(a[i]%num!=0) temp++;
    }
    return temp<=n;
}

int main(){
    cin >> n >> m;
    int l=1, r=0, mid=0;
    for(int i=0; i<m; i++){
        cin>>a[i];
        r = max(r,a[i]);
    }

    while(l<=r){
        mid = (l+r)/2;
        if(check(mid)){
            ans=min(ans,mid);
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }

    cout << ans <<'\n';
}