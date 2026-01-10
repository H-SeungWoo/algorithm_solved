#include<bits/stdc++.h>

using namespace std;

int n;
string str;

int main(){

    for(int i=0; i<3; i++){
        cin>>str;
        
        int a = atoi(str.c_str());
        if(a) n = a+(3-i); 
    }

    if(n%3==0||n%5==0){
        if(n%3==0 && n%5==0) cout<<"FizzBuzz"<<'\n';
        else if(n%3==0) cout <<"Fizz"<<'\n';
        else cout << "Buzz" <<'\n';
    }
    else cout << n <<'\n';

    return 0;
}