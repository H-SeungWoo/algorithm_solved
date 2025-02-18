#include <bits/stdc++.h>

using namespace std;

int n,m, ns[15001], ret=0;

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> ns[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ns[i]+ns[j] == m)
            {
                ret++;
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}