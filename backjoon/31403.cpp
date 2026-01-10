#include<bits/stdc++.h>

using namespace std;

int a,b,c;

int main()
{
    cin >> a >> b >> c;
    
    cout << a+b-c << '\n';
    cout << stoi(to_string(a)+to_string(b)) - c << '\n'; 
}