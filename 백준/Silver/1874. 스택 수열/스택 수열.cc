#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
int n, a[100004], m=1; 
vector<char> ret;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        while(a[i]>=m){
            stk.push(m);
            ret.push_back('+');
            m++;
            }
            
            if(!stk.empty() && a[i]==stk.top()){
                stk.pop();
                ret.push_back('-');
            }
    }

    if(stk.empty()) for(char ch: ret) cout << ch <<'\n';
    else cout << "NO"<<'\n';
    return 0;

}