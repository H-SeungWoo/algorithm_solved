#include<bits/stdc++.h>

using namespace std;

int n, cnt, ret, pre;
string str;
stack<char> stk;

int main(){

    cin>>n;
    cin>>str;

    //연속이 깨지는건 )가 들어와야 알게된다.
    //)이 들어왔을때 연속깨지는건 알기가 쉽다. 
    // ()
    for(char c: str){
        if(c=='('){
            stk.push(c);
        }
        else{
            if(stk.size()&&stk.top() =='('){
                cnt+=2;
                stk.pop();
            }
            else{
                ret = max(ret,pre);
                pre = 0;
                cnt = 0;
            }

        }

        if(stk.empty()){
            pre+=cnt;
            cnt=0;
        }
    }

    if(cnt) pre=max(pre,cnt);
    ret=max(ret,pre);
    cout<<ret<<'\n';
    return 0;
}