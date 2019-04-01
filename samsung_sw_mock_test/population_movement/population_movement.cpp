/*
 * https://www.acmicpc.net/problem/16234
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX = 50;

int n, l, r;

int moving[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int map[NMAX][NMAX];
int check[NMAX][NMAX];
bool visit[NMAX][NMAX];
int arr[NMAX * NMAX][2];	// x, y

void print() {
	cout << "= visit =" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	cout << "= map =" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "= check =" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
}

void initMap() {
	//	cout << "===== initMap =====" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = check[i][j];
			visit[i][j] = false;
		}
	}
	//	print();
}

bool isFound() {
	//	cout << "===== isFound =====" << endl;
	//	print();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != check[i][j]) {
				//				cout << "isFound = false" << endl;
				return false;
			}
		}
	}
	//	cout << "isFound = true" << endl;
	return true;
}

void bfs() {
	//	cout << "===== bfs =====" << endl;
		// find stop until answer
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int start = 0;
			int end = 1;
			int sum = map[i][j];
			int cnt = 1;
			if (!visit[i][j]) {
				arr[start][0] = i;
				arr[start][1] = j;
				visit[i][j] = true;
				while (start != end) {
					int curX = arr[start][0];
					int curY = arr[start][1];
					for (int k = 0; k < 4; k++) {
						int nextX = curX + moving[k][0];
						int nextY = curY + moving[k][1];
						if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
							int curVal = map[curX][curY];
							int nextVal = map[nextX][nextY];
							if (abs(curVal - nextVal) <= r && abs(curVal - nextVal) >= l && !visit[nextX][nextY]) {
								arr[end][0] = nextX;
								arr[end][1] = nextY;
								visit[nextX][nextY] = true;
								cnt++;
								sum += map[nextX][nextY];
								end++;
							}
						}
					}
					start++;
				}
			}

			for (int k = 0; k < start; k++) {
				check[arr[k][0]][arr[k][1]] = sum / cnt;
			}

			//			print();
		}
	}
}

int solve() {
	int round = 0;
	while (true) {
		//		cout << "========== round #" << round << " ==========" << endl;
		bfs();
		if (isFound()) {
			break;
		}
		else {
			initMap();
			round++;
		}
	}
	return round;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}

	cout << solve() << endl;
}
