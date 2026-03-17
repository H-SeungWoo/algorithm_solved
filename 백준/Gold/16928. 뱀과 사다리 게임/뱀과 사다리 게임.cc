#include <bits/stdc++.h>
using namespace std;

int n, m;
int moveTo[101];     // 사다리/뱀 정보. 없으면 0
int dist[101];       // 1번에서 해당 칸까지 최소 주사위 횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        moveTo[x] = y;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        moveTo[x] = y;
    }

    fill(dist, dist + 101, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; dice++) {
            int next = now + dice;
            if (next > 100) continue;

            if (moveTo[next] != 0) {
                next = moveTo[next];
            }

            if (dist[next] != -1) continue;

            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }

    cout << dist[100] << '\n';
    return 0;
}