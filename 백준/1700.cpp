#include<bits/stdc++.h>

using namespace std;

int n,k, a[100004], cnt;
map<int, int> mp;
unordered_set<int> s;
vector<int, int> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    
    for(int i=0; i<k; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    for(int i=0; i<k; i++){
        if(pq.size()<n){
            pq.push(a[i]);
            s.insert()
        }
        else{
            if()
        }
    }





    return 0;
}


// 적게쓰는 순서대로 빼기. (빈도 최소힙)
// 제일 나중에 오는 순서대로.