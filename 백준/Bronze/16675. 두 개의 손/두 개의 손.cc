#include<bits/stdc++.h>
using namespace std;

char ml,mr,tl,tr;

bool solve(char m, char t){
    return (m=='R'&& t=='S') || (m=='S'&& t=='P') || (m=='P'&& t=='R');
}

int main(){
    cin>>ml>>mr>>tl>>tr;

    if(ml == mr && tl == tr){
        if(ml==tl) cout<<"?\n";
        else if(solve(ml, tl)) cout<< "MS\n";
        else cout<< "TK\n";
    }
    else if(ml==mr){ 
        if(solve(tl, ml) || solve(tr, ml)){
            cout<<"TK\n";
        }
        else{
            cout<<"?\n";
        }
    }
    else if(tl==tr){
        if(solve(ml, tl) || solve(mr, tl)){
            cout<<"MS\n";
        }
        else{
            cout<<"?\n";
        }
    }
    else{
        cout<<"?\n";
    }

    return 0;
}