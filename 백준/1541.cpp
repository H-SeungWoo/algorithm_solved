#include<bits/stdc++.h>
using namespace std;

string str, temp;
int ret=1e9, sum;
vector<int> nums;
vector<char> opers;

int solve(int n1, int n2, char oper){
    if(oper=='+') return n1+n2;
    else return n1-n2;
}

int main(){
    cin>>str;

    for(char ch: str){
        if(ch>='0' && ch<='9'){
            temp += ch;    
        }
        else{
            nums.push_back(atoi(temp.c_str()));
            opers.push_back(ch);
            temp="";
        }
    }
    nums.push_back(atoi(temp.c_str()));

    int n = opers.size();

    for(int i=0; i<=n; i++){
        sum += nums[i];
        if(i==n) break;
        if(opers[i]=='-'){
            int temp_sum=0;
            for(int j=i+1; j<=n; j++){
                temp_sum+= nums[j];
            }
            sum -= temp_sum;
            break;
        }


        
    }

    cout<<sum<<'\n';
    return 0;

}