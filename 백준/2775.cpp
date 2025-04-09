#include<bits/stdc++.h>

using namespace std;

int t, k, n, sum;

int solve (int a, int b)
{
    cout << "-------\n";
    cout << "solve start. a: " << a << "b: " <<b <<'\n'; 
    if(a == 0) return  b;
    
    for(int i=1; i<=b; i++)
    {
        sum += solve(a-1, i);
    }

    return sum;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> k >> n;
        sum = 0;
        solve(k,n);
        cout << sum <<'\n';
    }

    return 0;
}