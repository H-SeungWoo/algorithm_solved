#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    
    while(n--)
    {
        stack<char> testStack;
        string testStr;
        cin >> testStr;
        for(char ch: testStr)
        {
            if(ch == '(')
            {
                testStack.push(ch);
            }
            else
            {
                if(!testStack.empty() && testStack.top() == '(' ) testStack.pop();
                else testStack.push(ch);
            }
        }

        if(testStack.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}