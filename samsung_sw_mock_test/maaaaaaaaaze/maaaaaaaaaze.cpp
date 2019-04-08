/* https://www.acmicpc.net/problem/16985 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


int moving[6][3] = { {0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1} };
int map[5][5][5];
int temp[5][5];
bool visit[5][5][5];
int arr[5];
bool vis[5];
int rot[5];

int cnt;

struct step {
	int x;
	int y;
	int h;
	step(int x_, int y_, int h_) {
		x = x_;
		y = y_;
		h = h_;
	}
};

void print(int cur) {
	cout << "print" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << map[cur][i][j] << " ";
		}
		cout << endl;
	}
}

void clockwise(int cur) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			temp[j][4 - i] = map[cur][i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[cur][i][j] = temp[i][j];
		}
	}
}

void bfs() {
	queue<step> q;
	step start(0, 0, 0);
	visit[arr[0]][0][0] = true;
	q.push(start);

	int curCount = 0;
	while (!q.empty()) {
		if (curCount > cnt)
			return;

		int qsize = q.size();
		while (qsize--) {
			step cur = q.front();
			//cout << "cur = " << arr[cur.h] << endl;
			//print(arr[cur.h]);
			q.pop();

			if (cur.x == 4 && cur.y == 4 && cur.h == 4) {
				cnt = min(cnt, curCount);
				return;
			}

			for (int i = 0; i < 6; i++) {
				int nx = cur.x + moving[i][0];
				int ny = cur.y + moving[i][1];
				int nh = cur.h + moving[i][2];
				if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nh >= 0 && nh < 5 && map[arr[nh]][nx][ny] == 1 && !visit[arr[nh]][nx][ny]) {
					visit[arr[nh]][nx][ny] = true;
					step next(nx, ny, nh);
					q.push(next);
				}
			}
		}
		curCount++;
	}
}

void rotate(int cur) {
	if (cur == 5) {
		if (map[arr[0]][0][0] == 1 && map[arr[4]][4][4] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						visit[i][j][k] = false;
					}
				}
			}
			bfs();
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		clockwise(arr[cur]);
		if ((cur == 0 && map[arr[cur]][0][0] != 1) || (cur == 4 && map[arr[cur]][4][4] != 1))
			continue;
		rotate(cur + 1);
	}
}

void solve(int cur) {
	if (cur == 5) {
		rotate(0);
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (!vis[i]) {
			vis[i] = true;
			arr[cur] = i;
			solve(cur + 1);
			vis[i] = false;
		}
	}

}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[i][j][k];
			}
		}
	}

	//init
	for (int i = 0; i < 5; i++) {
		vis[i] = false;
	}

	cnt = INT_MAX;
	solve(0);

	if (cnt == INT_MAX) cnt = -1;
	cout << cnt << endl;
}