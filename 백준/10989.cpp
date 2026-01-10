#include<bits/stdc++.h>

using namespace std;

int n, temp, cnt[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>temp;
        cnt[temp]++;
    }

    string out;
    out.reserve(1<<20);
    for(int i=1; i<=10000; i++){
        int a = cnt[i];
        while(a--){
            out += to_string(i);
            out += '\n';
            
            if(out.size() >= (1<<20)){
                cout<<out;
                out.clear();
            }
        }
    }

    if(!out.empty()){
        cout<<out;
    }
    
    return 0;
}