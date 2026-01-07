#include<bits/stdc++.h>

using namespace std;
int n, m;
unordered_map<int,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        mp[temp]++;
    }

    cin >> m;

    for(int i=0; i<m; i++)
    {
        int temp;
        cin>>temp;
        if(mp[temp]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}