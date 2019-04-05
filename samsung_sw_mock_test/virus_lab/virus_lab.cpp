/*
 * https://www.acmicpc.net/problem/14502
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NMAX = 8;

int n, m;
int wallCount;
int virusCount;

int moving[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int map[NMAX][NMAX];
int wall[NMAX*NMAX][2];
int virus[NMAX*NMAX][2];

int maxCount;

//void print() {
//	cout << "print map" << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

void setMap() {
    //init arr;
    int arr[NMAX][NMAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = map[i][j];
        }
    }

    //spead virus
    queue<pair<int, int>> q;
    for (int i = 0; i < virusCount; i++) {
        q.push(make_pair(virus[i][0], virus[i][1]));
    }

    int tempCnt = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        arr[x][y] = 2;
        for (int i = 0; i < 4; i++) {
            int nextX = x + moving[i][0];
            int nextY = y + moving[i][1];
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if (arr[nextX][nextY] == 0) {
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    //cout << "print arr" << endl;
    //for (int i = 0; i < n; i++) {
    //	for (int j = 0; j < m; j++) {
    //		cout << arr[i][j] << " ";
    //	}
    //	cout << endl;
    //}

    //count non-infected spots
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0)
                cnt++;
        }
    }

    //cout << "count = " << cnt << endl;
    //find max
    maxCount = max(maxCount, cnt);
}

void solve(int cur, int cnt) {
    if (cnt == 3) {
        //print();
        setMap();
        return;
    }

    for (int i = cur; i < wallCount; i++) {
        int x = wall[i][0];
        int y = wall[i][1];
        map[x][y] = 1;
        //cout << "wall at (" << x << ", " << y << ")" << endl;
        solve(i + 1, cnt + 1);
        map[x][y] = 0;
    }
}

int main() {
    cin >> n >> m;
    virusCount = 0;
    wallCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                wall[wallCount][0] = i;
                wall[wallCount][1] = j;
                wallCount++;
            }
            if (map[i][j] == 2) {
                virus[virusCount][0] = i;
                virus[virusCount][1] = j;
                virusCount++;
            }
        }
    }

    maxCount = 0;

    solve(0, 0);

    cout << maxCount << endl;
    cout << endl;
}