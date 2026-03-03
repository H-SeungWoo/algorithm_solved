#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int b; cin >> b;
            cout << A[i][j] + b << (j == M - 1 ? '\n' : ' ');
        }
    }
    return 0;
}