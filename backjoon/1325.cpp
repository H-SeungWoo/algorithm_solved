#include <bits/stdc++.h>

using namespace std;

int n, m, visited[10001], numHacking=0;
vector<int> adj[10001], ret;

int solve(int here)
{
    visited[here]=1;
    if(adj[here].size()==0) return 1;

    int numHacking = 1;
    for(int there: adj[here])
    {
        if(visited[there]) continue;
        numHacking += solve(there);
    }

    return numHacking;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp2].push_back(temp1);
    }

    for(int i=1; i<=n; i++)
    {
        fill(&visited[0], &visited[0]+10001, 0);
        int temp = solve(i);
        //cout << i <<"에서 해킹가능한 수 :" << temp <<'\n';
        if(numHacking < temp)
        {
            numHacking=temp;
            ret.clear();
            ret.push_back(i);
        }
        else if(numHacking == temp) ret.push_back(i);
    }

    for(int i: ret)
    {
        cout << i << ' ';
    }
    cout << '\n';
    
}