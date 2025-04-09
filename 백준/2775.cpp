#include<bits/stdc++.h>

using namespace std;

int t, k, n;

int solve (int a, int b)
{
    int sum = 0;
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
        cout << solve(k,n) <<'\n';
    }

    return 0;
}