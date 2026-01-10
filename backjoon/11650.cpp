#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first!=b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main()
{
    cin >> n;
    while(n--)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }   

    sort(v.begin(), v.end(), compare);

    for(auto p: v)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
}