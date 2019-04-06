/*
 * https://www.acmicpc.net/problem/14499
 */

#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 20;

int n, m, k;

int moving[5][2] = { {0,0}, {0,1}, {0,-1}, {-1,0}, {1,0} };
int map[NMAX][NMAX];
int dice[6];
int cur[2];

void print() {
    cout << "==== print dice ====" << endl;
    cout << "  " << dice[5] << endl;
    cout << dice[2] << " " << dice[0] << " " << dice[3] << endl;
    cout << "  " << dice[4] << endl;
    cout << "  " << dice[1] << endl;
    cout << "==== print map ====" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void east() {
    // top, bot, right, left, front, back
    int temp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[3];
    dice[3] = temp;
}

void west() {
    // top, bot, right, left, front, back
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = temp;
}

void north() {
    // top, bot, right, left, front, back
    int temp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[5];
    dice[5] = temp;
}

void south() {
    // top, bot, right, left, front, back
    int temp = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[4];
    dice[4] = temp;
}

void solve(int x, int y, int dir) {
    int nx = x + moving[dir][0];
    int ny = y + moving[dir][1];

    //cout << "======== new roll ========" << endl;
    //cout << "dir = " << dir << " (" << x << ", " << y << ") -> (" << nx << ", " << ny << ")" << endl;
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (dir == 1) {
            east();
        }
        else if (dir == 2) {
            west();
        }
        else if (dir == 3) {
            north();
        }
        else {
            south();
        }
        //cout << "map[nx][ny] = " << map[nx][ny] << endl;
        if (map[nx][ny] == 0)
            map[nx][ny] = dice[1];
        else {
            dice[1] = map[nx][ny];
            map[nx][ny] = 0;
        }
        //print();

        cur[0] = nx;
        cur[1] = ny;
        cout << dice[0] << endl;
    }
    //else {
    //	cout << "invalid move" << endl;
    //}
}

int main() {
    cin >> n >> m >> cur[0] >> cur[1] >> k;
    //init
    for (int i = 0; i < 6; i++)
        dice[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;
        solve(cur[0], cur[1], dir);

    }
    cout << endl;
}