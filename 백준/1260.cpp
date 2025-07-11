#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    cout << v << ' ';
    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';

        for (int i = 0; i < graph[v].size(); i++) {
            int next = graph[v][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end()); 
    }

    dfs(v);
    cout << '\n';

    fill(visited, visited + 1001, false);
    bfs(v);
    cout << '\n';

    return 0;
}