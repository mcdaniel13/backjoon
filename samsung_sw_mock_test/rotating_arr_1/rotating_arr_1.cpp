/*
	https://www.acmicpc.net/problem/16926
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 300;

int n, m, k;

int map[NMAX][NMAX];

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void rotate() {
	int cnt = min(n, m) / 2;
	int cur = 0;

	int cn = n;
	int cm = m;
	while (cnt--) {
		int cx = cur;
		int cy = cur;
		int next = 0;
		int prev = map[cx][cy];

		cx++;
		for (int i = 0; i < cn - 1; i++) {
			next = map[cx][cy];
			map[cx][cy] = prev;
			prev = next;
			cx++;
		}

		cx--; cy++;
		for (int i = 0; i < cm - 1; i++) {
			next = map[cx][cy];
			map[cx][cy] = prev;
			prev = next;
			cy++;
		}

		cy--; cx--;
		for (int i = 0; i < cn - 1; i++) {
			next = map[cx][cy];
			map[cx][cy] = prev;
			prev = next;
			cx--;
		}

		cx++; cy--;
		for (int i = 0; i < cm - 1; i++) {
			next = map[cx][cy];
			map[cx][cy] = prev;
			prev = next;
			cy--;
		}
		cur++;
		cn -= 2;
		cm -= 2;
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		rotate();
	}

	print();
}