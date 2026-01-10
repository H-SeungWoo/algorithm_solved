#include<bits/stdc++.h>

using namespace std;

int n,m;
unordered_map<string, int> listenless;
vector<string> listenandwatchless;

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        string temp;
        cin >> temp;
        listenless[temp]++;
    }

    for(int i=0; i<m; i++)
    {
        string temp;
        cin >> temp;
        if(listenless[temp] == 0) continue;
        
        listenandwatchless.push_back(temp);
    }

    sort(listenandwatchless.begin(), listenandwatchless.end());
    cout<<listenandwatchless.size() <<'\n';
    for(string s: listenandwatchless)
    {
        cout << s << '\n';
    }
    return 0;
}
