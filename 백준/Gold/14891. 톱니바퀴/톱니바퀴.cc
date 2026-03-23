#include <bits/stdc++.h>
using namespace std;

int k;
int gear[5][8]; // 1~4번 톱니 사용

void rotate(int num, int dir) {
    if (dir == 1) { // 시계 방향
        int temp = gear[num][7];
        for (int i = 7; i >= 1; i--) {
            gear[num][i] = gear[num][i - 1];
        }
        gear[num][0] = temp;
    }
    else if (dir == -1) { // 반시계 방향
        int temp = gear[num][0];
        for (int i = 0; i < 7; i++) {
            gear[num][i] = gear[num][i + 1];
        }
        gear[num][7] = temp;
    }
}

void solve(int gearNum, int dir) {
    int rotateDir[5] = {0}; 
    rotateDir[gearNum] = dir;

    // 왼쪽 전파
    for (int i = gearNum; i > 1; i--) {
        if (gear[i][6] != gear[i - 1][2]) {
            rotateDir[i - 1] = -rotateDir[i];
        } else {
            break;
        }
    }

    // 오른쪽 전파
    for (int i = gearNum; i < 4; i++) {
        if (gear[i][2] != gear[i + 1][6]) {
            rotateDir[i + 1] = -rotateDir[i];
        } else {
            break;
        }
    }

    // 한 번에 회전
    for (int i = 1; i <= 4; i++) {
        if (rotateDir[i] != 0) {
            rotate(i, rotateDir[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            gear[i][j] = s[j] - '0';
        }
    }

    cin >> k;
    while (k--) {
        int gearNum, dir;
        cin >> gearNum >> dir;
        solve(gearNum, dir);
    }

    int score = 0;
    if (gear[1][0] == 1) score += 1;
    if (gear[2][0] == 1) score += 2;
    if (gear[3][0] == 1) score += 4;
    if (gear[4][0] == 1) score += 8;

    cout << score << '\n';
    return 0;
}