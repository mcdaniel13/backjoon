/*
 * https://www.acmicpc.net/problem/15683
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 8;
const int CCTV_MAX = 8;

int map[NMAX][NMAX];
int visit[NMAX][NMAX];
int cctv[CCTV_MAX][2];	// x,y 좌표
int moving[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int n, m;
int cCount;
int zCount;
int minSpot;

void print() {
    cout << "==== map ====" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "==== visit ====" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
}

int visiting(int x, int y, int type, int i) {
    int counting = 0;
    while (true) {
        x = x + moving[i][0];
        y = y + moving[i][1];
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (map[x][y] == 6)
                break;

            if (map[x][y] == 0) {
                visit[x][y] = type;
                map[x][y] = 9;
                counting++;
            }
        }
        else {
            break;
        }
    }
    return counting;
}

void clearing(int x, int y, int type, int i) {
    while (true) {
        x = x + moving[i][0];
        y = y + moving[i][1];
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (map[x][y] == 6)
                break;

            if (visit[x][y] == type) {
                visit[x][y] = 0;
                map[x][y] = 0;
            }
        }
        else {
            break;
        }
    }
}

void solve(int cur, int changed) {
    if (cur == cCount) {
        //cout << "changed = " << changed << endl;
        int result = zCount - changed;
        minSpot = min(result, minSpot);
        return;
    }

    int x = cctv[cur][0];
    int y = cctv[cur][1];
    if (map[x][y] == 1) {
        for (int i = 0; i < 4; i++) {
            //cout << "type 1 : " << i << endl;
            int curChanged = visiting(x, y, cur + 10, i);
//			print();
            solve(cur + 1, changed + curChanged);
            clearing(x, y, cur + 10, i);
//			print();
        }
    }
    else if (map[x][y] == 2) {
        for (int i = 0; i < 2; i++) {
            //cout << "type 2 : " << i  << ", " << (i + 2) % 4 << endl;
            int curChanged = visiting(x, y, cur + 10, i);
            curChanged += visiting(x, y, cur + 10, (i + 2) % 4);
            //print();
            solve(cur + 1, changed + curChanged);
            clearing(x, y, cur + 10, i);
            clearing(x, y, cur + 10,(i + 2) % 4);
            //print();
        }
    }
    else if (map[x][y] == 3) {
        for (int i = 0; i < 4; i++) {
            //cout << "type 3 : " << i << ", " << (i + 1) % 4 << endl;
            int curChanged = visiting(x, y, cur + 10, i);
            curChanged += visiting(x, y, cur + 10, (i + 1) % 4);
            //print();
            solve(cur + 1, changed + curChanged);
            clearing(x, y, cur + 10, i);
            clearing(x, y, cur + 10, (i + 1) % 4);
            //print();
        }
    }
    else if (map[x][y] == 4) {
        for (int i = 0; i < 4; i++) {
            //cout << "type 4 : " << i << ", " << (i + 1) % 4 << ", " << (i + 2) % 4 << endl;
            int curChanged = visiting(x, y, cur + 10, i);
            curChanged += visiting(x, y, cur + 10, (i + 1) % 4);
            curChanged += visiting(x, y, cur + 10, (i + 2) % 4);
            //print();
            solve(cur + 1, changed + curChanged);
            clearing(x, y, cur + 10, i);
            clearing(x, y, cur + 10, (i + 1) % 4);
            clearing(x, y, cur + 10, (i + 2) % 4);
            //print();
        }
    }
    else if (map[x][y] == 5) {
        //cout << "type = 5" << endl;
        int curChanged = 0;
        for (int i = 0; i < 4; i++) {
            curChanged += visiting(x, y, cur + 10, i);
        }
        //print();
        solve(cur + 1, changed + curChanged);
        for (int i = 0; i < 4; i++) {
            clearing(x, y, cur + 10, i);
        }
        //print();
    }
}

int main() {
    cin >> n >> m;
    cCount = 0;
    zCount = 0;

    //init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                zCount++;
            else if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctv[cCount][0] = i;
                cctv[cCount][1] = j;
                cCount++;
            }
        }
    }

    minSpot = NMAX * NMAX;
    solve(0, 0);

    cout << minSpot << endl;
    cout << endl;
}