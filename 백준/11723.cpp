#include<bits/stdc++.h>

using namespace std;

int n, x, s;
string command;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> n;
    for(int i=0; i<n; i++)
    {
        cin >> command;
        if(command == "add")
        {
            cin>>x;
            s |= (1<<x);
        }
        else if (command == "remove")
        {
            cin >> x;
            s &= ~(1<<x);
        }
        else if (command == "check")
        {
            cin >> x;
            cout << ((s & (1<<x))? 1:0) << '\n';
        }
        else if (command == "toggle")
        {
            cin >> x;
            s ^= (1<<x);
        }
        else if (command == "all")
        {
            s = (1<<21)-1;
        }
        else if (command == "empty")
        {
            s = 0;
        }
    }
    return 0;
}