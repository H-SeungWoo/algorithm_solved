#include<bits/stdc++.h>

using namespace std;

int t, n, pointer;
string queries, temp, ans;
vector<int> v, v2;

vector<int> Split(const string& input,string delimiter){
    vector<int> result;
    int start = 0;
    int end = input.find(delimiter);
    while(end!=string::npos){
        int temp = atoi(input.substr(start,end-start).c_str());
        if(temp) result.push_back(temp);
        start = end+delimiter.size();
        end = input.find(delimiter, start);
    } 
    int temp = atoi(input.substr(start).c_str());
    if(temp) result.push_back(temp);

    return result;
}

string solvePrint(vector<int> ans){
    string ret ="[";
    for(int i=0; i<ans.size();i++){
        ret +=to_string(ans[i]);
        if(i!=ans.size()-1){
            ret+=",";
        }
    }
    ret+="]";
    return ret;
}

int main(){

    cin>>t;
    while(t--){
        cin>>queries>>n;

        cin>>temp;

        v = Split(temp.substr(1,temp.size()-2),",");
        v2.clear();

        int l=0, r=v.size();
        bool Rdir=1, bError=0;
        //Rdir가 1이면 정방향, 0면 역방향.
        for(char querie: queries){
            if(querie =='R'){
                Rdir ^= 1;
            }
            else if(querie == 'D'){
                if(l>=r){
                    bError= true;
                    break;
                }
                
                if(Rdir&1){ // 정방향
                    l++;
                }
                else{
                    r--;
                }

            }
        }
        if(bError) cout<<"error"<<'\n';
        else{
            for(int i=l; i<r; i++){
                v2.push_back(v[i]);
            }
            if(!(Rdir&1)) reverse(v2.begin(), v2.end());
            cout<<solvePrint(v2)<<'\n';
        }
    }

    return 0;
}