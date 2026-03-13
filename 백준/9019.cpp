#include<bits/stdc++.h>
using namespace std;

int t, visited[10004];
pair<int,int> prev_visited[10004];

int rotate(int x, char mode){
    string temp = to_string(x);

    // 자리수 0 보강해주기.
    while(temp.size()<4){
        temp = "0" + temp;
    }

    if(mode=='L'){
        temp+=temp[0];
        return atoi(temp.substr(1,4).c_str());
    }
    else{
        temp += temp.substr(0,3);
        return atoi(temp.substr(3,4).c_str());
    }
}

stack<char> stk_push(stack<char> stk, int mode){


    return stk;
}

string solve(int a, int b){
    int x = a;
    queue<int> q;
    
    q.push(a);
    visited[a]=1;
    while(q.size()){
        x = q.front(); q.pop();
        if(visited[b]) break;

        int dx[4] = {x*2, x-1, rotate(x,'L'), rotate(x,'R')};
        for(int i=0; i<4; i++){
            int nx = dx[i];
            if(nx>9999) nx %= 10000;
            if(nx==-1) nx = 9999;

            if(visited[nx]) continue;
            visited[nx] = visited[x] +1;
            q.push(nx);

            prev_visited[nx] = {x, i};
        }
    }


// 역추적으로 명령어 추적하기
    int prev = prev_visited[b].first;
    int mode = prev_visited[b].second;
    stack<char> stk;
    string ret ="";

    while(prev != -1){
        if(mode == 0) stk.push('D');
        else if(mode == 1) stk.push('S');
        else if(mode == 2) stk.push('L');
        else if(mode == 3) stk.push('R');
        
        mode = prev_visited[prev].second;
        prev = prev_visited[prev].first;
    }

    while(!stk.empty()){
        ret+=stk.top();
        stk.pop();
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        fill(visited, visited+10004, 0);
        fill(prev_visited, prev_visited+10004, make_pair(-1,-1));


        cout<<solve(a,b)<<'\n';
    }

    return 0;

}