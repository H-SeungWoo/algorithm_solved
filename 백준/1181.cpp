#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> dir;

bool compare(string &a, string &b)
{
    if(a.size() != b.size())
    {
        return a.size()<b.size();
    }
    return a <b;
}

int main()
{
    cin>>n;

    while(n--)
    {
        string temp;
        cin >> temp;
        dir.push_back(temp);
    }

    sort(dir.begin(), dir.end(), compare);
    auto new_end = unique(dir.begin(), dir.end());
    dir.erase(new_end, dir.end());

    for(string s: dir)
    {
        cout << s << '\n';
    }

    return 0;
}