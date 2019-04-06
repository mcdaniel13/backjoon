/*
 * https://www.acmicpc.net/problem/12100
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int NMAX = 20;

int n;

int map[NMAX][NMAX];
int maxVal;
//void print() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

void calculateMax() {
    int tempMax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempMax = max(map[i][j], tempMax);
        }
    }
    //cout << "max = " << tempMax << endl;
    maxVal = max(tempMax, maxVal);
}

void up() {
    //cout << "== up ====" << endl;
    queue<int> q;
    for (int j = 0; j < n; j++) {
        //cout << "= col #" << j + 1 << " =" << endl;
        //get vale at same col
        for (int i = 0; i < n; i++) {
            if (map[i][j] != 0) {
                q.push(map[i][j]);
            }
            map[i][j] = 0;
        }

        int index = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (map[index][j] == 0)
                map[index][j] = cur;
            else {
                if (map[index][j] == cur) {
                    map[index][j] *= 2;
                    index++;
                }
                else {
                    index++;
                    map[index][j] = cur;
                }
            }
        }
    }
}

void down() {
    //cout << "== down ==" << endl;
    queue<int> q;
    for (int j = 0; j < n; j++) {
        //cout << "= col #" << j + 1 << " =" << endl;
        //get vale at same col
        for (int i = n - 1; i >= 0; i--) {
            if (map[i][j] != 0) {
                q.push(map[i][j]);
            }
            map[i][j] = 0;
        }

        int index = n - 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (map[index][j] == 0)
                map[index][j] = cur;
            else {
                if (map[index][j] == cur) {
                    map[index][j] *= 2;
                    index--;
                }
                else {
                    index--;
                    map[index][j] = cur;
                }
            }
        }
    }
}

void left() {
    //cout << "== left ==" << endl;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        //cout << "= row #" << i + 1 << " =" << endl;
        //get vale at same col
        for (int j = 0; j < n; j++) {
            if (map[i][j] != 0) {
                q.push(map[i][j]);
            }
            map[i][j] = 0;
        }

        int index = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (map[i][index] == 0)
                map[i][index] = cur;
            else {
                if (map[i][index] == cur) {
                    map[i][index] *= 2;
                    index++;
                }
                else {
                    index++;
                    map[i][index] = cur;
                }
            }
        }
    }
}

void right() {
    //cout << "== right ==" << endl;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        //cout << "= row #" << i + 1 << " =" << endl;
        //get vale at same col
        for (int j = n - 1; j >= 0; j--) {
            if (map[i][j] != 0) {
                q.push(map[i][j]);
            }
            map[i][j] = 0;
        }
        int index = n - 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (map[i][index] == 0)
                map[i][index] = cur;
            else {
                if (map[i][index] == cur) {
                    map[i][index] *= 2;
                    index--;
                }
                else {
                    index--;
                    map[i][index] = cur;
                }
            }
        }
    }
}


void solve(int cnt) {
    if (cnt == 5) {
        //cout << "====== cnt reaches 5 ======" << endl;
        //print();
        calculateMax();
        return;
    }

    int backup[NMAX][NMAX];

    //init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            backup[i][j] = map[i][j];
        }
    }

    up();
    //print();
    solve(cnt + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = backup[i][j];
        }
    }


    down();
    //print();
    solve(cnt + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = backup[i][j];
        }
    }

    right();
    //print();
    solve(cnt + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = backup[i][j];
        }
    }

    left();
    //print();
    solve(cnt + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = backup[i][j];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    maxVal = 0;
    solve(0);
    cout << maxVal << endl;
}