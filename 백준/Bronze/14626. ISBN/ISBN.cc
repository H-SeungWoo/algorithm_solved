#include<bits/stdc++.h>

using namespace std;

int n, m, sum, ret, idx, w=1;
string str;


int main(){
    cin>>str;


    for(int i=0; i<13; i++){
        if(str[i]=='*'){
            if(i&1) w=3;
            idx=i;
            continue;
        }

        if(i&1) sum += 3*(str[i]-'0');
        else sum += (str[i]-'0');
    }

    for(int i=0; i<10; i++){
        if((sum+w*i)%10 == 0){
            cout << i <<'\n';
        }
    }

    return 0;
}