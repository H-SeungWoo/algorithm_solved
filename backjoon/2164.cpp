#include<bits/stdc++.h>

using namespace std;

int n, ret;

int main()
{
    cin >> n;

    queue<int> q;

    for(int i=1; i<=n;i++)
    {
        q.push(i);
    }

    while(!q.empty() && q.size() != 1)
    {
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    ret = q.front();
    cout << ret << '\n';
    return 0;
}