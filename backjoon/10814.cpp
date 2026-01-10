#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, string>> v;

bool compare(const pair<int, string> &a,const pair<int, string> &b)
{  
    return a.first < b.first;
}

int main()
{
    cin >> n;
    while(n--)
    {
        int temp1;
        string temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }

    stable_sort(v.begin(), v.end(), compare);
    
    for(auto p: v)
    {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}