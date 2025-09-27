#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll lo, hi, n, a[100004], cnt[100004], ret;


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];        
    }
    
    while(hi<n){
        if(!cnt[a[hi]]){
            cnt[a[hi]]++;
            hi++;
        }else{
            ret += (hi-lo);
            cnt[a[lo]]--;
            lo++;
        }
    }

    // 나머지 부분에서 만들어지는 경우의수 더해야됨
    // 길이 1 -> (hi-lo)개. 길이 2->(hi-lo)-1개 ... 길이 (hi-lo) -> 1개
    // 등차수열 합 = 평균*개수
    // 평균 --> (hi-lo+1)/2 | 개수 --> (hi-lo)
    ret += (ll) (hi-lo)*(hi-lo+1)/2;
    cout<<ret<<'\n';
    return 0;
}

// i=0 -> j=0,1,2,3,4
// cnt++ 0~
