#include <bits/stdc++.h>

using namespace std;

string s;

bool checkStr(string str)
{
    stack<char> stk;

    for(char ch: str)
    {
        if(ch == ')' || ch ==']')
        {
            if(stk.empty()) return false;
            if(ch==')' && stk.top() == '[' || ch==']' && stk.top() == '(') return false;
            else
            {
                if(ch == ')' && stk.top() =='(') stk.pop();
                else if (ch == ']' && stk.top() == '[') stk.pop();
            }
        }
        else if(ch == '(' || ch == '[') stk.push(ch);
    }

    return stk.empty();
}

int main()
{
    while(true)
    {
        getline(cin, s);
        
        if(s==".") break;

        if(checkStr(s)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}