#include <iostream>

using namespace std;

int arr[26] = {0};
string s;

int main()
{
    cin >> s;
    for(char c : s) arr[c - 'a']++;
    for(int i: arr) cout << i << " ";
    return 0;
}