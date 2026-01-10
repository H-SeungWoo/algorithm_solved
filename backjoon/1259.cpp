#include<bits/stdc++.h>

using namespace std;

int test;

int main()
{

    while(true)
    {
        cin >> test;
        if(test == 0) break;
        string s;
        s = to_string(test);
        
        if(s.size()%2 == 1) // 홀수
        {
            string temp = s.substr(s.size()/2+1);
            reverse(temp.begin(), temp.end());

            if(s.substr(0,s.size()/2) == temp ) cout << "yes" <<'\n';
            else cout << "no" <<'\n';

        }
        else
        {
            string temp = s.substr(s.size()/2);
            reverse(temp.begin(), temp.end());

            if(s.substr(0,s.size()/2) == temp) cout << "yes" <<'\n';
            else cout << "no" <<'\n';
        }
    }

    return 0;
}