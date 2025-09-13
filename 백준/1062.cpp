#include<bits/stdc++.h>

using namespace std;

vector<int> words;
int n, k, ret;
string s;

int cnt(int mask){
    int cnt = 0;
    for(int i: words){
        if(i && (i&mask)==i) cnt++;
    }
    return cnt;
}

int solve(int idx, int pk, int mask){
    if(pk>k) return 0;
    if(idx==26) return cnt(mask);

    int ret = solve(idx+1, pk+1, mask|1<<(idx));
    if((idx!= 'a'-'a')&&(idx!='n'-'a')&&(idx!= 't'-'a')&&(idx!='i'-'a')&&(idx!='c'-'a')){
        ret = max(ret, solve(idx+1, pk, mask));
    }
    return ret;
}

int main(){
    words.resize(50);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin >> s;
        for(char c: s){
            words[i] |= 1<<(c-'a');
        }  
    }

    cout<<solve(0,0,0)<<'\n';

}