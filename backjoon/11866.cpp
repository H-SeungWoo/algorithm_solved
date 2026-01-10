#include<bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        q.push(i);
    }

    cout<<"<";
    while(q.size() > 1)
    {
        int cnt = 1;
        while(cnt != k)
        {
            cnt++;
            q.push(q.front());
            q.pop();
        }
        cout << q.front()<<", ";
        q.pop();
    }
    if(!q.empty()) cout<<q.front();
    cout<<">"<<'\n';
    return 0;
}