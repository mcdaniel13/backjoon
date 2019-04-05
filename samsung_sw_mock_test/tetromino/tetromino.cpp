#include <iostream>
#include <algorithm>

using namespace std;

const int MMAX = 500;

int n, m;

int moving[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int except[4][4][2] = { {{0,0},{0,-1},{0,1},{1,0}},
						{{0,0},{0,-1},{0,1},{-1,0}},
						{{0,0},{-1,0},{1,0},{0,1}},
						{{0,0},{-1,0},{1,0},{0,-1}} };

int map[MMAX][MMAX];
bool visit[MMAX][MMAX];
int maxSum;

void dfs(int x, int y, int cur, int sum) {
	if (cur == 4) {
		maxSum = max(maxSum, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + moving[i][0];
		int ny = y + moving[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
			visit[nx][ny] = true;
			dfs(nx, ny, cur + 1, sum + map[nx][ny]);
			visit[nx][ny] = false;
		}
	}

}

void solveException(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		bool isTrue = true;
		for (int j = 0; j < 4; j++) {
			int nx = x + except[i][j][0];
			int ny = y + except[i][j][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				sum += map[nx][ny];
			else {
				isTrue = false;
				break;
			}
		}
		if (isTrue)
			maxSum = max(maxSum, sum);

	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			dfs(i, j, 1, map[i][j]);
			visit[i][j] = false;

			solveException(i, j);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}

	maxSum = 0;

	solve();

	cout << maxSum << endl;
}