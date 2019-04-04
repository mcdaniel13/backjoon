/*
 * https://www.acmicpc.net/problem/14891
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string magnet[4];
int top[4];
int rot[4];

int n;

void calculatePoints() {
    int points = 0;
    for (int i = 0; i < 4; i++) {
        if (magnet[i][top[i]] == '1') {
            points += pow(2, i);
        }
    }
    cout << points << endl;
}

void changeTop() {
    for (int i = 0; i < 4; i++) {
        if (rot[i] == -1) {
            top[i] = (top[i] + 1) % 8;
        }
        else if (rot[i] == 1) {
            top[i] = (top[i] + 7) % 8;

        }
    }
}

void solve(int origin, int cur, int dir) {
    if (cur >= origin && cur + 1 < 4) {
        if (magnet[cur][(top[cur] + 2) % 8] != magnet[cur + 1][(top[cur + 1] + 6) % 8]) {
            rot[cur + 1] = -1 * dir;
            solve(origin, cur + 1, rot[cur + 1]);
        }
    }

    if (cur <= origin && cur - 1 >= 0) {
        if (magnet[cur][(top[cur] + 6) % 8] != magnet[cur - 1][(top[cur - 1] + 2) % 8]) {
            rot[cur - 1] = -1 * dir;
            solve(origin, cur - 1, rot[cur - 1]);
        }
    }
}

int main() {
    //init
    for (int i = 0; i < 4; i++) {
        cin >> magnet[i];
        top[i] = 0;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int cur, dir;
        cin >> cur >> dir;

        //init rotational direction
        for (int i = 0; i < 4; i++)
            rot[i] = 0;

        rot[cur - 1] = dir;
        solve(cur - 1, cur - 1, rot[cur - 1]);
        changeTop();
    }

    calculatePoints();
}