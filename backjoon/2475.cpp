#include <bits/stdc++.h>

using namespace std;

int n, sum = 0;

int main()
{
    for(int i=0; i<5; i++)
    {
        cin>>n;
        sum += n*n;
    }

    cout << sum%10 << '\n';
}
