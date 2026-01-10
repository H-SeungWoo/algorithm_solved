#include <bits/stdc++.h>

using namespace std;

int n, c, a[1001];
vector<pair<int,int>> v;
map<int,int> mp, msg_first_index;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if(a.second == b.second) 
    {
        return msg_first_index[a.first] < msg_first_index[b.first];
    }
    else return a.second > b.second;
}

int main()
{
    cin >> n >> c;
    for(int i=0; i<n; i++)
    {
        cin >> a[i]; 
        mp[a[i]]++;
        if(msg_first_index[a[i]] == 0) msg_first_index[a[i]] = i+1;
    }

    for(auto it: mp)
    {
        v.push_back({it.first, it.second});
    }

    sort(v.begin(), v.end(), compare);
    
    for(auto it: v)
    {
        while(it.second--)
        {
            cout << it.first << " ";
        }
    }
    return 0;
}