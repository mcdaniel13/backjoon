/*
 * https://www.acmicpc.net/problem/14503
 */

#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 50;
const int MMAX = 50;

int n, m;

int moving[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int map[NMAX][MMAX];
int cur[3];		// x,y,dir
int result;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void calculate() {
    result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                result++;
            }
        }
    }
}

void solve() {
    queue < pair<pair<int, int>, int>> q;

    q.push(make_pair(make_pair(cur[0], cur[1]), cur[2]));
    // done cleaning at current point;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;

        map[x][y] = 2;
        //cout << "curPoint = (" << x << ", " << y << ") dir = " << dir << endl;
        //print();
        q.pop();

        bool isBack = true;
        //rotate the machine
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4;
            int xNext = x + moving[dir][0];
            int yNext = y + moving[dir][1];
            if (xNext >= 0 && xNext < n && yNext >= 0 && yNext < m) {
                if (map[xNext][yNext] == 0) {	//possible to clean
                    //cout << "nextPoint = (" << xNext << ", " << yNext << ") dir = " << dir << endl;
                    q.push(make_pair(make_pair(xNext, yNext), dir));
                    isBack = false;
                    break;
                }
            }
        }
        if (isBack) {
            int dirNext = (dir + 2) % 4;
            int xNext = x + moving[dirNext][0];
            int yNext = y + moving[dirNext][1];
            if (xNext >= 0 && xNext < n && yNext >= 0 && yNext < m) {
                if (map[xNext][yNext] != 1) {
                    //cout << "nextPoint (back) = (" << xNext << ", " << yNext << ") dir = " << dir << endl;
                    q.push(make_pair(make_pair(xNext, yNext), dir));
                }
                else {
                    break;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> cur[0] >> cur[1] >> cur[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    //print();
    solve();
    calculate();
    cout << result << endl;
    cout << endl;
}