#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NMAX = 20;
const int MMAX = 20;

int n, m, bcnt, ecnt;

struct stone {
	int x;
	int y;
	stone() {}
	stone(int xx, int yy) {
		x = xx;
		y = yy;
	}
};

int moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int map[MMAX][MMAX];
bool visit[MMAX][MMAX];
stone black[NMAX*NMAX];
stone zero[MMAX * MMAX];
int result;

void print() {
	cout << "====" << endl;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void bfs() {
	int total = 0;
	for (int i = 0; i < bcnt; i++) {
		if (!visit[black[i].x][black[i].y]) {
			visit[black[i].x][black[i].y] = true;
			queue<stone> q;
			q.push(black[i]);

			bool flag = true;
			int cnt = 1;
			while (!q.empty()) {
				stone cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.x + moving[i][0];
					int ny = cur.y + moving[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (map[nx][ny] == 0) 	//open
							flag = false;
						else if (map[nx][ny] == 0)
							continue;
						else if (map[nx][ny] == 2 && !visit[nx][ny]) {
							visit[nx][ny] = true;
							q.push(stone(nx, ny));
							cnt++;

						}
					}
				}
			}
			if (flag) {
				total += cnt;
			}
		}
	}
	result = max(result, total);
}

void solve(int cnt, int index) {
	if (cnt == 2) {
		for (int i = 0; i < bcnt; i++)
			visit[black[i].x][black[i].y] = false;

		bfs();
		return;
	}
	//select two locations for white stone
	for (int i = index; i < ecnt; i++) {
		stone cur = zero[i];
		map[cur.x][cur.y] = 1;
		solve(cnt + 1, i + 1);
		map[cur.x][cur.y] = 0;
	}
}

int main() {
	cin >> n >> m;
	bcnt = 0;
	ecnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero[ecnt] = stone(i, j);
				ecnt++;
			}
			else if (map[i][j] == 2) {
				black[bcnt] = stone(i, j);
				bcnt++;
			}
		}
	}

	result = 0;
	solve(0, 0);
	cout << result << endl;
}