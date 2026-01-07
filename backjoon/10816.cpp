#include<bits/stdc++.h>

using namespace std;

int n,m;
unordered_map<int, int> cards;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        cards[temp]++;
    }

    cin>>m;
    for(int i=0; i<m; i++)
    {
        int temp;
        cin>> temp;
        cout << cards[temp] << ' ';
    }

    cout << '\n';
}