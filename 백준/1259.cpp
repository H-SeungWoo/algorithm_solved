#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    while (cin >> test && test != 0) 
    {
        string s = to_string(test);
        string leftPart = s.substr(0, s.size() / 2);
        string rightPart = s.substr((s.size() + 1) / 2); // 짝수/홀수 모두 고려

        reverse(rightPart.begin(), rightPart.end());

        cout << (leftPart == rightPart ? "yes" : "no") << '\n';
    }
    return 0;
}