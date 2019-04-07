/*
	https://www.acmicpc.net/problem/17069
*/

#include <iostream>

using namespace std;

const int NMAX = 33;

int n;
int sx, sy;

// 0 = left ; 1 = downleft; 2 = down;
int moving[3][2] = { {0, 1}, {1, 1}, {1, 0} };
int map[NMAX][NMAX];
long long dp[NMAX][NMAX][3];
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

void print() {
	cout << "=== left === " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j][0] << " ";
		}
		cout << endl;
	}
	cout << "=== diag === " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j][1] << " ";
		}
		cout << endl;
	}
	cout << "=== down === " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j][2] << " ";
		}
		cout << endl;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "====== cur = " << i << ", " << j << " ======" << endl;
			if (i == 0 && j == 0 || map[i][j] == 1)
				continue;

			//move horizontal
			if (map[i][j + 1] == 0) {
				dp[i][j + 1][0] = dp[i][j][0] + dp[i][j][1];
			}

			//move vertical
			if (map[i + 1][j] == 0) {
				dp[i + 1][j][2] = dp[i][j][2] + dp[i][j][1];
			}

			//move diagonal
			if (map[i + 1][j + 1] == 0 && map[i + 1][j] == 0 && map[i][j + 1] == 0) {
				dp[i + 1][j + 1][1] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
			}
			//print();
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			//init
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
			dp[i][j][2] = 0;
		}
	}

	dp[0][1][0] = 1;

	solve();

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << endl;
	cout << endl;
}