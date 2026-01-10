#include<bits/stdc++.h>

using namespace std;

const int INF = 2000000001;
int n, a[100001], ret=INF, idx1, idx2;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int l=0, r=n-1;
    while(l<r){
        int sum = a[l] + a[r];

        if(ret>=abs(sum)){
            ret = abs(sum);
            idx1=l;
            idx2=r;
        }
         
        if(sum<=0) l++;
        else if(sum>0) r--;
    }


    cout << a[idx1] << ' '<< a[idx2] <<'\n';
    return 0;

}