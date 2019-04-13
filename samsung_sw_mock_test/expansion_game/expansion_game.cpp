/*
 * https://www.acmicpc.net/problem/16920
 */

#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 1000;
const int PMAX = 10;

int n, m, p;

int moving[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

char map[NMAX][NMAX];
queue<pair<int, int>> player[PMAX];
int s[PMAX];
int result[PMAX];

int main() {
	cin >> n >> m >> p;

	for(int i = 1; i <= p; i++) {
		cin >> s[i];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j] - '0' >= 1 && map[i][j] - '0' <= 9) {
				player[map[i][j] - '0'].push(make_pair(i, j));
				result[map[i][j] - '0']++;
			}
		}
	}

	while(true) {
		bool flag = true;
		for (int i = 1; i <= p; i++) {
			if (player[i].empty())
				continue;

			for (int k = 0; k < s[i]; k++) {
				int qsize = player[i].size();

				if(qsize == 0)
					break;

				while (qsize--) {
					int x = player[i].front().first;
					int y = player[i].front().second;
					player[i].pop();
					for (int j = 0; j < 4; j++) {
						int nx = x + moving[j][0];
						int ny = y + moving[j][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (map[nx][ny] == '.') {
								flag = false;
								map[nx][ny] = i + '0';
								player[i].push(make_pair(nx, ny));
								result[i]++;
							}
						}
					}
				}
			}
		}

		if(flag)
			break;
	}

	for(int i = 1; i <= p; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}