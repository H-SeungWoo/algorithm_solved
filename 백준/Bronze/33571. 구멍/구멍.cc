#include<bits/stdc++.h>

using namespace std;
string str;
int ret;
int solve(char ch){
    if(ch=='A' || ch=='a' || ch=='D' || ch=='d' || 
        ch == 'e' || ch == 'g' || ch=='O' || ch =='o' ||
        ch == 'P' || ch == 'p' || ch =='Q' || ch == 'q' ||
        ch == 'R' || ch == 'b' || ch =='@') return 1;
    else if(ch=='B') return 2;
    else return 0;
}

int main(){

    getline(cin, str);
    for(char ch: str){
        ret += solve(ch);
    }
    cout<<ret<<'\n';
    return 0;
}