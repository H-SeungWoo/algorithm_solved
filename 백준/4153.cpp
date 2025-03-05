#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void solve(int a, int b, int c)
{
    if(a*a + b*b == c*c) 
    {
        cout << "right" << '\n';
        return;
    }
        
    cout << "wrong" << '\n';
}
int main()
{
    while(true)
    {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;

        int maxlength = max(max(a, b),c);

        if(maxlength == a) solve(b, c, a);
        else if(maxlength == b) solve(c, a, b);
        else if (maxlength == c) solve(a, b, c);
        
    }

    return 0;
}