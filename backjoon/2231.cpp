#include <bits/stdc++.h>

using namespace std;

int n, ret = 0;

int main()
{
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int temp = 0;
        for(char c: to_string(i))
        {
            temp += c-'0';
        }

        if(n == i+temp) 
        {
            ret = i;
            break;
        }
    }

    cout << ret <<'\n';
    return 0;
}