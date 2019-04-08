#include <iostream>
#include <queue>

using namespace std;

int map[5][5][5];
int temp[5][5];
bool visit[5][5][5];

int cnt;
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
	queue<pair<int, int>> q;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[0][i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	while(!q.empty())
}

void rotate() {
	if (cur == 5) {
		bfs();
		return;
	}

	for (int i = 0; i < 4; i++) {
		clockwise(cur);
		solve(cur + 1);
	}
}

void solve(int cur) {
	for (int i = cur; i < 5; i++) {

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

	solve(0);
	cout << cnt << endl;
	cout << endl;
}