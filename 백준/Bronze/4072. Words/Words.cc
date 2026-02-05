#include<bits/stdc++.h>
using namespace std;

string str;

vector<string> split(const string& input, string delimiter){
    vector<string> ret;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos){
        ret.push_back(input.substr(start, end-start));
        start = end+delimiter.size();
        end =  input.find(delimiter, start);
    }
    ret.push_back(input.substr(start));
    return ret;
}

int main(){
    while(getline(cin, str)){
        if(str=="#") break;

        vector<string> strs = split(str," ");
        for(string s: strs){
            reverse(s.begin(), s.end());
            cout<<s<<' ';
        }
        cout<<'\n';
    }
}