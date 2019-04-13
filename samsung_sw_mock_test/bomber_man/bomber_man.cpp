/*
	https://www.acmicpc.net/problem/16918
*/
#include <iostream>

using namespace std;

const int NMAX = 200;

int r, c, n;


int moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char map[2][NMAX][NMAX];
int cnt[NMAX][NMAX];

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[0][i][j];
		}
		cout << endl;
	}
}

void solve() {
	for (int t = 1; t < n; t++) {
		//cout << "=== t =" << t + 1 << " ===" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[0][i][j] == '.') {
					map[1][i][j] = 'O';
					cnt[i][j] = 3;
				}
				else if (map[0][i][j] == 'O') {
					cnt[i][j]--;
					if (cnt[i][j] == 0) {
						map[1][i][j] = '.';
						for (int k = 0; k < 4; k++) {
							int nx = i + moving[k][0];
							int ny = j + moving[k][1];
							if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
								map[1][nx][ny] = '.';
							}
						}
					}
					else {
						if (map[1][i][j] != '.')
							map[1][i][j] = 'O';
					}
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				map[0][i][j] = map[1][i][j];
			}
		}
	}

}

int main() {
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[0][i][j];
			if (map[0][i][j] == 'O') {
				cnt[i][j] = 2;
			}
		}
	}

	solve();
	print();
	cout << endl;
}