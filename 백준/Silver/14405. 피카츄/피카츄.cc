#include<bits/stdc++.h>

using namespace std;

string str, check;
stack<char> stk;


int main(){
    cin>>str;
    for(int i=0; i<str.size()-1; i ++){
        if(str[i] == 'p' && str[i+1] =='i') check += "pi";
        if(str[i] == 'k' && str[i+1] =='a') check += "ka";
        if(str[i] == 'c')
        if (i < str.size()-2 && str[i+1] =='h' && str[i+2] == 'u') check += "chu";
    }

    if(str==check) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return 0;
}
