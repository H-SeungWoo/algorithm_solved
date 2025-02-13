#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        m=1;
        cnt = 1;
        while(true)
        {
            if(m%n==0)
            {
                cout<<cnt<<'\n';
                break;
            }
            else
            {

                m = (10* m)+1;
                m %= n;
                cnt++;
            }
        }
    }
    return 0;
}