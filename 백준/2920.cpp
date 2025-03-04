#include<bits/stdc++.h>

using namespace std;

int a[10];
bool isAsceding = true, isDescending = true;

int main()
{
    for(int i=0; i<8; i++)
    cin >>a[i];

    for(int i=0; i<8; i++)
    {
        if(a[i] != i+1) isAsceding = false;
        if(a[i] != 8-i) isDescending = false; 
    }

    if(isAsceding && !isDescending) cout << "ascending" << '\n';
    else if(!isAsceding && isDescending) cout << "descending" << '\n';
    else cout << "mixed" << '\n';
}