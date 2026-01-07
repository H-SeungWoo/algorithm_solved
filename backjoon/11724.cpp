#include<bits/stdc++.h>

using namespace std;

int n, m, cnt;
vector<int> adj[1004];
int visited[1004];

void solve(int here)
{
    visited[here] = 1;
    for(int there: adj[here])
    {
        if(visited[there]) continue;
        solve(there);
    }
}
int main()
{

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            solve(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
}