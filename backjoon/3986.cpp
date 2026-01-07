#include <bits/stdc++.h>

using namespace std;

stack<char> stk;
string s;
int n, cnt;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >>s;
        for(char ch: s)
        {
            if(!stk.empty()&&stk.top()==ch) stk.pop();
            else stk.push(ch);
        } 

        if(stk.empty()) cnt++;
        while(!stk.empty())
        {
            stk.pop();
        }
    }

    cout << cnt << '\n';

    return 0;
}