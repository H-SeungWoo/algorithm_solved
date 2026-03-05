#include<bits/stdc++.h>
using namespace std;

int n, m, ans, cnt;
string s;
bool conti;
char a[1000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // O면, 전에거가 I인지 체크해.
    // I면, 전에거가 O인지 체크하면서 O전에가 I였는지 체크해.
    // 그럼 IOI 완성.
    // 연속 중이냐 아니냐의 판별.
    // 연속중이라면
    cin>>n>>m>>s;
    for(int i=2; i<m; i++){
        if(s[i]=='I'){
            if(s[i-1]=='O' && s[i-2] == 'I') cnt++;
            else{
                if(cnt>=n) ans += cnt -(n-1); 
                cnt = 0;
            }
        }

    }

    if(cnt>=n) ans += cnt -(n-1); 
    
    cout<<ans<<'\n';
    return 0;
}
