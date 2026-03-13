#include<bits/stdc++.h>

using namespace std;

int n, m, k, cnt, known;
int knowns[51];
vector<int> parties[51];

int main(){

    cin>>n>>m;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>> known;
        knowns[known] = 1;
    }

    for(int i=0; i<m; i++){
        int visitor_n = 0;
        cin>>visitor_n;

        for(int j=0; j<visitor_n; j++){
            int visitor = 0;
            cin>>visitor;
            parties[i].push_back(visitor);

        }

    }

    bool changed = true;
    while(changed)
    {
        changed = false;

        for(int i=0; i<m; i++){
            bool truth = false;

            for(int visitor: parties[i]){
                //cout<<visitor<<" knows?: " << knowns[visitor]<<' ';
                if(knowns[visitor]){
                    truth = true;
                    break;
                }
            }

            if(truth){
                for(int visitor: parties[i]){
                    if(!knowns[visitor]){
                        knowns[visitor] = 1;
                        changed = true;
                    }
                }           
            }

        }

    }


    for(int i=0; i<m; i++){
        bool canLie = true;
        for(int visitor : parties[i]){
            if(knowns[visitor]){
                canLie = false;
                break;
            }
        }
        if(canLie) cnt++;
    }        
        
    cout<<cnt<<'\n';
    return 0;
}