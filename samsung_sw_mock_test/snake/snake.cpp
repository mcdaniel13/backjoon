/*
 * https://www.acmicpc.net/problem/3190
 */
#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 100;
const int LMAX = 100;
int n, k, l;

int moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int map[NMAX][NMAX];
int snake[LMAX][2];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int solve() {
    //init snake
    int sx = 0;
    int sy = 0;
    int dir = 0;
    queue<pair<int, int>> q;
    map[sx][sy] = 1;
    q.push(make_pair(sx, sy));

    int t = 0;
    int i = 0;
    while (!q.empty()) {
        //cout << "====round #" << t << " ====" << endl;
        if (snake[i][0] == t && i < l) {
            dir = (dir + snake[i][1]) % 4;
            i++;
            //cout << "snake change its direction to dir = " << dir << endl;
        }

        sx += moving[dir][0];
        sy += moving[dir][1];
        //cout << "cur = (" << sx << ", " << sy << ")" << endl;
        if (sx >= 0 && sx < n && sy >= 0 && sy < n) {
            if (map[sx][sy] != 1) {
                if (map[sx][sy] == 0) {
                    int px = q.front().first;
                    int py = q.front().second;
                    map[px][py] = 0;
                    q.pop();
                }
                map[sx][sy] = 1;
                q.push(make_pair(sx, sy));
                t++;
                //print();
            } else {
                //cout << "break" << endl;
                break;
            }
        }
        else {
            //cout << "break" << endl;
            break;
        }
    }

    return t + 1;
}

int main() {
    cin >> n >> k;
    //init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = 0;
        }
    }

    //input
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        map[row - 1][col - 1] = 2;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        char dir;
        cin >> snake[i][0] >> dir;
        if (dir == 'L')
            snake[i][1] = 3;
        else
            snake[i][1] = 1;
    }

    cout << solve() << endl;
    cout << endl;
}