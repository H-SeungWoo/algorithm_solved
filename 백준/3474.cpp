#include <bits/stdc++.h>

using namespace std;

int n, testCase, numOf2, numOf5 ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while(n--)
    {
        cin >> testCase;

        numOf2 = 0;
        numOf5 = 0;

        for(int i = 2; i <= testCase; i *= 2)
        {
            numOf2 += testCase/i;
        }

        for(int i = 5; i <= testCase; i *= 5)
        {
            numOf5 += testCase/i;
        }
            
        cout << min(numOf2 , numOf5) << '\n';
    }
    return 0;
}