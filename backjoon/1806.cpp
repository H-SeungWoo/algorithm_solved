#include<bits/stdc++.h>

using namespace std;

const int INF = 123456789;
typedef long long ll;
int psum[100001];
int n, a[100001], s, ret=INF;

int main(){
    cin>> n >> s;

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        psum[i] = psum[i-1]+a[i];
    }

    int l=1, r=1;
    do{
        ll sum = psum[r]-psum[l-1];
        if(sum>=s && ret>(r-l+1)){
            ret = r-l+1;
            //cout<<r<<":"<<l<<'\n';
        }

        // 0 5 6 9 14 24 31 35 44 46 54

        if(sum<s)r++;
        else l++;

        if(r>n) break;

    }while(l<=r);

    if(ret==INF) ret = 0;

    cout<<ret<<'\n';

}