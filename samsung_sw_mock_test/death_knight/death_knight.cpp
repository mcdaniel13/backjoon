#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 200;

int n;

struct knight {
	int x;
	int y;
	knight(int nx, int ny) {
		x = nx;
		y = ny;
	}
};

int moving[6][2] = { {-2, -1,}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };
int map[NMAX][NMAX];
bool visit[NMAX][NMAX];

int solve(knight start, knight end) {
	int result = 0;
	queue<knight> q;
	q.push(start);
	visit[start.x][start.y] = true;

	int time = 0;
	bool flag = false;
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			knight cur = q.front();
			q.pop();

			if (cur.x == end.x && cur.y == end.y) {
				flag = true;
				break;
			}

			for (int i = 0; i < 6; i++) {
				int nx = cur.x + moving[i][0];
				int ny = cur.y + moving[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push(knight(nx, ny));
				}
			}
		}
		if (flag)
			break;
		time++;
	}

	if (flag)
		return time;
	else
		return -1;
}

int main() {
	cin >> n;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	knight start(sx, sy);
	knight end(ex, ey);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = false;


	cout << solve(start, end) << endl;
	cout << endl;
}
