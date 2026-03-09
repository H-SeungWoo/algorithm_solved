#include<bits/stdc++.h>
using namespace std;

int t, a, b; 
vector<int> c[11];

int main(){

    cin>> t;

    c[0] = {10};
    c[1] = {1};
    c[2] = {2, 4, 8, 6};
    c[3] = {3, 9, 7, 1};
    c[4] = {4, 6};
    c[5] = {5};
    c[6] = {6};
    c[7] = {7, 9, 3, 1};
    c[8] = {8, 4, 2, 6};
    c[9] = {9, 1};

    while(t--){
        cin>>a>>b;
        
        int x = a%10;
        int y = c[x].size();
        cout << c[x][(b-1)%y] <<'\n';
    }


    return 0;
}