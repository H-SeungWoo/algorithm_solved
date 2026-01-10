#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int visited[MAX+4], prePosition[MAX+4];
int n, k;
queue<int> q;
stack<int> stk;

int main()
{
    cin >> n >> k;

    q.push(n);
    visited[n] = 1;

    while(q.size())
    {
        int nowPosition = q.front(); q.pop();
        for(int nextPosition: {nowPosition+1, nowPosition-1, nowPosition*2})
        {
            if(nextPosition <0 || nextPosition>MAX) continue;
            if(!visited[nextPosition])
            {
                q.push(nextPosition);
                visited[nextPosition] = visited[nowPosition] +1;
                prePosition[nextPosition] = nowPosition;
                //cout << nowPosition << " -> " << nextPositions[nowPosition] << " == " << nextPosition << '\n';
            }
        }

        if(nowPosition == k) break;
    }

    cout<<visited[k]-1<<'\n';
    int temp = k;
    for(int i=0; i< visited[k]; i++)
    {
        stk.push(temp);
        temp = prePosition[temp];
    }

    while(stk.size())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout<<'\n';

    return 0;
}