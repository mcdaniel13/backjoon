/*
	https://www.acmicpc.net/problem/17070
*/

#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 16;

int n;
int sx, sy;

// 0 = left ; 1 = downleft; 2 = down;
int moving[3][2] = { {0, 1}, {1, 1}, {1, 0} };
int map[NMAX][NMAX];
int ans;

struct pipe {
	int x;
	int y;
	int dir;
	pipe(int x_, int y_, int dir_) {
		x = x_;
		y = y_;
		dir = dir_;
	}
};

void print(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x == i && y == j) {
				cout << 'H' << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {
	queue<pipe> q;
	pipe start(sx, sy, 0);
	q.push(start);

	while (!q.empty()) {
		pipe cur = q.front();
		q.pop();

		int cx = cur.x;
		int cy = cur.y;
		int cdir = cur.dir;
		//cout << "======== cur = " << cx << ", " << cy << "========" << endl;

		if (cx == n - 1 && cy == n - 1)
			ans++;

		for (int i = 0; i < 3; i++) {
			//exception at moving direction
			if ((cdir == 0 && i == 2) || (cdir == 2 && i == 0))
				continue;

			//find the next possible place for head
			int nx = cx + moving[i][0];
			int ny = cy + moving[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (((i == 0 || i == 2) && (map[nx][ny] == 0))
					|| ((i == 1) && (map[nx][ny] == 0 && map[cx][ny] == 0 && map[nx][cy] == 0))) {
					//cout << "==== next = " << nx << ", " << ny << " dir = " << i << "====" << endl;
					pipe next(nx, ny, i);
					q.push(next);
					//print(nx, ny);
				}
			}
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
	if (map[0][0] == 0 && map[0][1] == 0 && map[0][2] == 0) {
		sx = 0;
		sy = 1;
		//print(sx, sy);

		ans = 0;;
		solve();
		cout << ans << endl;
	}
	else {
		cout << '0' << endl;
	}
}