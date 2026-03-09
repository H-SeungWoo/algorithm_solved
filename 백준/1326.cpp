#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int s, e;
    cin >> s >> e;

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == e) break;

        int jump = a[cur];

        for (int next = cur + jump; next <= n; next += jump) {
            if (dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
        for (int next = cur - jump; next >= 1; next -= jump) {
            if (dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[e] << "\n";
    return 0;
}