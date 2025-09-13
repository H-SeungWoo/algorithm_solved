#include<bits/stdc++.h>

using namespace std;

int n, cnt, ret=0;
int coin[21];

int check(int num){
    int fcnt;
    for(int i=num; num>0; i>>1){
        if(i&1) fcnt++;
    }

    return fcnt;
}

// 행을 뒤집는다. 그게 인덱스 관리 편하니까.
// 즉, 1차원배열에 10011 이런 수를 넣을거다.

int main(){

    cin>>n;

    for(int i=0; i<n; i++){
        int mask = 0;
        for(int j=0; j<n; j++){
            char temp;
            cin>>temp;
            int bit = (temp=='T');
            mask = (mask<<1)|bit;
        }
        coin[i] = mask;
    }

    for(int i=0; i<(1<<n); i++){
        cnt =0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                coin[j] = ~coin[j]; 
            }
            //개수세기
            cnt += check(coin[j]);
        }
        ret = min(cnt, ret);
    }

    return 0;
}