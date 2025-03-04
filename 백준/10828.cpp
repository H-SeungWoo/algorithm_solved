#include<bits/stdc++.h>

using namespace std;

int n;
string s;
stack<int> stk;

int main()
{
    cin >> n;
    string bufferFlush;
    getline(cin, bufferFlush);
    while(n--)
    {
        getline(cin ,s);
        if(s == "pop")
        {
            if(stk.size()) 
            {
                cout << stk.top() <<'\n';
                stk.pop();
            }
            else cout << -1 << '\n';
        }
        else if(s == "size") cout << stk.size() <<'\n';
        else if(s == "empty") cout << stk.empty() << '\n';
        else if(s == "top")
        {
            if(stk.size()) cout << stk.top() <<'\n';
            else cout << -1 << '\n';
        }
        else // push인 경우
        {
            stk.push(atoi(s.substr(5).c_str()));
        }
    }

    return 0;
}