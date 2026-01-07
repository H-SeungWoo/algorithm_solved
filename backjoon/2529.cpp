#include<bits/stdc++.h>

using namespace std;

bool visited[10];
char a[10];
int n;
vector<string> ret;

bool cmp(int x, int y, char c){
    if(c=='<') return x<y;
    return x>y;
}

void solve(int depth, string num){
    
    if(depth == n+1){
        ret.push_back(num);
        return;       
    }

    for(int i=0; i<=9; i++)
    {
        if(visited[i]) continue;
        if(depth==0 || cmp(num[depth-1], i+'0', a[depth-1] )){
            visited[i] = 1;
            solve(depth +1, num + to_string(i));
            visited[i] = 0;
            
        }
    }
    return ;

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    solve(0,"");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size()-1] << '\n' << ret[0] << '\n';

    return 0;
}