/*
 * https://www.acmicpc.net/problem/13460
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NMAX = 10;

int n, m;

int moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char map[NMAX][NMAX];
bool visit[NMAX][NMAX][NMAX][NMAX];
int srx, sry, sbx, sby;
int minCount;

struct Current {
	int rx;
	int ry;
	int bx;
	int by;
	int round;

	Current(int rx_, int ry_, int bx_, int by_, int round_) {
		rx = rx_; ry = ry_; bx = bx_, by = by_, round = round_;
	}
};

void print(int rx, int ry, int bx, int by) {
	cout << "cur r = (" << rx << ", " << ry << ") cur b = (" << bx << ", " << by << ")" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (rx == i && ry == j) {
				cout << 'R' << " ";
				continue;
			}
			if (bx == i && by == j) {
				cout << 'B' << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				for (int l = 0; l < m; l++)
					visit[i][j][k][l] = false;
}

void solve() {
	queue<Current> q;
	Current start(srx, sry, sbx, sby, 0);
	q.push(start);
	visit[srx][sry][sbx][sby] = true;

	int round = 0;
	while (!q.empty()) {
		//int qsize = q.size();
		//while (q.size() > 0) {
		Current cur = q.front();
		q.pop();
		//qsize--;

		if (cur.round > 10)
			break;

		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			minCount = min(minCount, cur.round);
			break;
		}

		for (int i = 0; i < 4; i++) {
			int rx = cur.rx;
			int ry = cur.ry;
			int bx = cur.bx;
			int by = cur.by;

			while (true) {
				int nrx = rx + moving[i][0];
				int nry = ry + moving[i][1];
				if (map[nrx][nry] == '#' || map[rx][ry] == 'O')
					break;
				rx = nrx;
				ry = nry;
			}

			while (true) {
				int nbx = bx + moving[i][0];
				int nby = by + moving[i][1];
				if (map[nbx][nby] == '#' || map[bx][by] == 'O')
					break;
				bx = nbx;
				by = nby;
			}

			if (rx == bx && ry == by) {
				if (map[bx][by] == 'O')
					continue;
				if (abs(rx - cur.rx) + abs(ry - cur.ry) < abs(bx - cur.bx) + abs(by - cur.by)) {
					bx -= moving[i][0];
					by -= moving[i][1];
				}
				else {
					rx -= moving[i][0];
					ry -= moving[i][1];
				}
			}

			//if (rx == 5 && ry == 5) {
			//	cout << "reach!" << endl;
			//}

			if (!visit[rx][ry][bx][by]) {
				//cout << "dir = " << i << " cur = " << cur.round << endl;
				//print();
				Current next(rx, ry, bx, by, cur.round + 1);
				q.push(next);
				visit[rx][ry][bx][by] = true;
			}
		}
		//{
		//if (round == 10) {
		//	break;
		//}
		//round++;
	}
}

int main() {
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				srx = i;
				sry = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				sbx = i;
				sby = j;
				map[i][j] = '.';
			}
		}
	}

	//print();
	minCount = 11;
	solve();
	if (minCount == 11) minCount = -1;

	cout << minCount << endl;
	cout << endl;
}