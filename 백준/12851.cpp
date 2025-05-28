#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int visited[MAX+4], cnt[MAX+4];
int n, k;
queue<int> q;

void solve()
{
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);
    while(q.size())
    {
        int x = q.front(); q.pop();
        
        for(int nx: {x-1, x+1, x*2})
        {
            if(nx<0 || nx>MAX) continue;
            //cout << visited[x] << " : " << x << " -> " << nx <<'\n';
            if(!visited[nx])
            {   
                q.push(nx);
                visited[nx] = visited[x]+1;
                cnt[nx] += cnt[x];
            }

            else if(visited[nx] == visited[x]+1)
            {
                cnt[nx] += cnt[x];
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    if(n==k)
    {
        puts("0"); puts("1");
        return 0;
    }

    solve();
    cout << visited[k]-1 <<'\n';
    cout << cnt[k] <<'\n';

    return 0;
}

