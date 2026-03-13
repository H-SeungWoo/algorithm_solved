#include<bits/stdc++.h>
using namespace std;

int n, ans, fruits[10], a[200004];

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int l=0, cnt=0;
    for(int r=0; r<n; r++){
        if(fruits[a[r]] == 0) cnt++;
        fruits[a[r]]++;

        while(cnt>2){
            //왼쪽은 무조건 옮길거니까 일단 빼고 봐.
            fruits[a[l]]--;
            // 그리고 옮기기전에 비교. 옮긴 후는 새로운 과일이 있을 수도 있으니까.
            if(fruits[a[l]]==0) cnt--;

            l++;
            
        }

        ans = max(ans, r-l+1);
    }

    cout<<ans<<'\n';
    return 0;
}