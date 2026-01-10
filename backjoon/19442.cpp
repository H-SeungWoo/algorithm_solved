#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, mp, mf, ms, mv, ret=INF;
int sump,sumf,sums,sumv,sumc;
map<int, vector<vector<int>>> ret_v;
struct foods{
    int p,f,s,v,c;
}food[16];

 

int main(){

    cin>>n;
    cin>>mp>>mf>>ms>>mv;
    for(int i=0; i<n; i++){
        cin>>food[i].p>>food[i].f>>food[i].s>>food[i].v>>food[i].c;
    }

    // 포함하냐 안하냐의 경우의수. 2의 n승개(공집합 제외-> 1부터시작) 
    for(int i=1; i<(1<<n); i++){
        sump=sumf=sums=sumv=sumc=0;
        vector<int> idxs;
        //idx번째 비트가 켜져있냐 안켜져있냐를 확인. 그러므로, j는 인덱스 그 자체이다.
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                sump+=food[j].p;
                sumf+=food[j].f;
                sums+=food[j].s;
                sumv+=food[j].v;
                sumc+=food[j].c;
                idxs.push_back(j+1);
            }
        }

        if(sump>=mp&&sumf>=mf&&sums>=ms&&sumv>=mv&&sumc<=ret){
            ret = sumc;
            ret_v[ret].push_back(idxs);
        }
    }

    sort(ret_v[ret].begin(), ret_v[ret].end());
    if(ret==INF) cout << -1 <<'\n';
    else{
        cout << ret <<'\n';
        for(int a: ret_v[ret][0]){
            cout << a << " ";
        }
        cout<<'\n';
        
    }

    return 0;

}