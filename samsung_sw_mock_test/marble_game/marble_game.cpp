/*
 * https://www.acmicpc.net/problem/13460
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NMAX = 10;

int n, m;

int moving[4][2] = { {0,1}, {1,0}, {0,-1},{-1,0} };
char map[NMAX][NMAX];
int minCnt;
bool visit[10][10][10][10];

struct Cond {
	int rx;
	int ry;
	int bx;
	int by;
	Cond(int rx_, int ry_, int bx_, int by_) {
		rx = rx_;
		ry = ry_;
		bx = bx_;
		by = by_;
	}
};

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void solve(int srx, int sry, int sbx, int sby) {
	queue<Cond> q;
	Cond start(srx, sry, sbx, sby);
	q.push(start);
	visit[srx][sry][sbx][sby] = true;

	int cnt = 0;
	while(!q.empty()) {
		int qlen = q.size();
		while (qlen > 0) {
			qlen--;
			Cond cur = q.front();
			q.pop();

			if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
				minCnt = cnt;
				return;
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
					if (abs(rx - cur.rx) + abs(ry - cur.ry) > abs(bx - cur.bx) + abs(by - cur.by)) {
						rx -= moving[i][0];
						ry -= moving[i][1];
					} else {
						bx -= moving[i][0];
						by -= moving[i][1];
					}
				}

				if (!visit[rx][ry][bx][by]) {
					Cond next(rx, ry, bx, by);
					q.push(next);
					visit[rx][ry][bx][by] = true;
				}
			}
		}
		if (cnt == 10) {
			minCnt = -1;
			return;
		}
		cnt++;
	}
	minCnt = -1;
}

int main() {
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				bx = i;
				by = j;
				map[i][j] = '.';
			}
		}
	}

	//init
	for(int i = 0; i < 10; i++)
		for(int j = 0; i < 10; i++)
			for(int k = 0; i < 10; i++)
				for(int l = 0; i < 10; i++)
					visit[i][j][k][l] = false;


	solve(rx, ry, bx, by);
	cout << minCnt << endl;

}