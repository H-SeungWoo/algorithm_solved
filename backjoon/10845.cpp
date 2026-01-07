#include<bits/stdc++.h>

using namespace std;

int n;
string s;
queue<int> q;

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
            if(q.size()) 
            {
                cout << q.front() <<'\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if(s == "size") cout << q.size() <<'\n';
        else if(s == "empty") cout << q.empty() << '\n';
        else if(s == "front")
        {
            if(q.size()) cout << q.front() <<'\n';
            else cout << -1 << '\n';
        }
        else if(s == "back")
        {
            if(q.size()) cout << q.back() <<'\n';
            else cout << -1 << '\n';
        }
        else // push인 경우
        {
            q.push(atoi(s.substr(5).c_str()));
        }
    }

    return 0;
}