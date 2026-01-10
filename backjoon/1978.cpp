#include<bits/stdc++.h>

using namespace std;

int n, cnt, temp;
bool isPrime;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> temp;

        isPrime = true;
        if(temp == 1) continue;
        for(int i=2; i*i<=temp; i++)
        {
            if(temp%i==0)
            {
                isPrime= false;
                break;
            }
        }
        if(isPrime) cnt ++;
    }

    cout << cnt << '\n';
    return 0;
}