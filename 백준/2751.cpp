#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    while(n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    
    for(int i: v)
    {
        cout << i << '\n';
    }

    return 0;
}