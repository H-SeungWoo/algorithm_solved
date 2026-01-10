#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, k;

int solve(){
    vector<int> dist(100004, INF);
    deque<int> dq;
    dist[n] = 0;
    dq.push_back(n);

    while(dq.size()){
        int x = dq.front(); dq.pop_front();
        if(x==k) break;

        
        for(int nx: {x+1, x-1, x*2}){
            if(nx<0 || nx>100000) continue;
            if(nx==x*2 && dist[nx] > dist[x]){
                dist[nx] = dist[x];
                dq.push_front(nx);
            }
            else{
                if(dist[nx]>dist[x]+1){
                    dist[nx] = dist[x] +1;
                    dq.push_back(nx);
                }
            }
        }

    }

    return dist[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>k;
    if(n>=k){
        cout << n-k << '\n';
        return 0;
    }

    cout<<solve()<<'\n';
    return 0;

}