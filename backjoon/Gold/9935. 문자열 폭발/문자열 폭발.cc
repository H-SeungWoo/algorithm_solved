#include<bits/stdc++.h>
using namespace std;

int cnt, pos;
string str, bomb, ret;


int main(){
    cin>>str>>bomb;

    for(char c: str){
        ret += c;
        if(ret.size()>=bomb.size()&&ret.substr(ret.size()-bomb.size(),bomb.size())==bomb){
            ret.erase(ret.size()-bomb.size(),bomb.size());            
        }
    }
    if(ret=="") cout<<"FRULA"<<'\n';
    else cout << ret <<'\n';

    return 0;
}