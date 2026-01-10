#include<bits/stdc++.h>

using namespace std;

const int MAX = 500000;
int visited[2][MAX+4]; 
int n, k; // 위치
int t=1; // 시간
bool canCatch;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    if(n==k)
    {
        cout<<0<<'\n';
        return 0;
    }

    visited[0][n] = 1;
    q.push(n);

    while(q.size())
    {
        k += t;
        if(k>MAX) break;
        if(visited[t%2][k])
        {
            canCatch = true;
            break;
        }

        int qSize = q.size();
        for(int i=0; i<qSize; i++)
        {
            int nowPosition = q.front(); q.pop();
            for(int nextPosition : {nowPosition+1, nowPosition-1, nowPosition*2})
            {
                if(nextPosition<0 || nextPosition>MAX ) continue;
                if(visited[t%2][nextPosition]) continue;

                visited[t%2][nextPosition] = visited[(t+1)%2][nowPosition]+1;

                if(nextPosition == k)
                {
                    canCatch = true;
                    break;
                }
                q.push(nextPosition);
            }
            if(canCatch) break;
        }
        if(canCatch) break;

        t++;
    }

    if(canCatch) cout<<t<<'\n';
    else cout<<-1<<'\n';


    return 0;
}