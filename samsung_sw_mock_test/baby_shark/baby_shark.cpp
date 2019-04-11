/*
 * https://www.acmicpc.net/problem/16236
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NMAX = 20;

int n;

struct shark {
	int x;
	int y;
	int dist;
	shark() {}
	shark(int nx, int ny, int nd) {
		x = nx;
		y = ny;
		dist = nd;
	}
};

int moving[4][2] = { {-1,0}, {0,-1},{0,1},{1,0} };
int map[NMAX][NMAX];
bool visit[NMAX][NMAX];
int fcnt, ssize;
shark start;

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = false;
}

bool compare(shark one, shark two) {
	if (one.dist == two.dist) {
		if (one.x == two.x)
			return one.y < two.y;
		else
			return one.x < two.x;
	}
	else
		return one.dist < two.dist;
}

shark bfs() {
	queue<shark> q;
	vector<shark> fish;

	init();

	q.push(start);
	visit[start.x][start.y] = true;


	while (!q.empty()) {
		shark cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + moving[i][0];
			int ny = cur.y + moving[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
				if (map[nx][ny] <= ssize) {
					visit[nx][ny] = true;
					if (map[nx][ny] < ssize && map[nx][ny] != 0) {
						fish.push_back(shark(nx, ny, cur.dist + 1));
					}
					q.push(shark(nx, ny, cur.dist + 1));
				}
			}
		}
	}

	if (!fish.size()) {
		return shark(0, 0, 0);
	}
	else {
		sort(fish.begin(), fish.end(), compare);
		return fish[0];
	}
}

int solve() {
	ssize = 2;
	int eat = 0;
	int ecnt = 0;
	int dist = 0;
	while (ecnt < fcnt) {
		shark next = bfs();
		if (next.dist == 0)
			break;
		else {	// found
			dist += next.dist;
			eat++;
			ecnt++;
			start = shark(next.x, next.y, 0);
			map[next.x][next.y] = 0;
		}

		if (eat == ssize) {
			ssize++;
			eat = 0;
		}
	}

	return dist;
}

int main() {
	cin >> n;

	fcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] <= 6)
				fcnt++;
			if (map[i][j] == 9) {
				start = shark(i, j, 0);
				map[i][j] = 0;
			}
		}
	}

	cout << solve() << endl;
}