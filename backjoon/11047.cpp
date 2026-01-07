#include <bits/stdc++.h>

using namespace std;

int n, k, ret;
stack<int> coins; 

int main()
{
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        coins.push(temp);
    }

    while(coins.size())
    {
        if(coins.top() <= k) 
        {   
            int temp = k/coins.top();
            ret += temp;
            k -= temp * coins.top();
        }
        coins.pop();

    }

    cout << ret << '\n';
    return 0;
}