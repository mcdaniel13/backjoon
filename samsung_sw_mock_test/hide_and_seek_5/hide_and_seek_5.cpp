/* 
	https://www.acmicpc.net/problem/17071
*/

#include <iostream>
#include <queue>

using namespace std;

int n, k;
const int KMAX = 500001;

bool subin[2][KMAX];		// even = 0; odd = 1;
int minTime;

struct Subin {
	int n;
	int k;
	Subin(int n_, int k_) {
		n = n_;
		k = k_;
	}
};

void init() {
	minTime = -1;

	for (int i = 0; i < KMAX; i++) {
		subin[0][i] = false;
		subin[1][i] = false;
	}
}

void moveSubin() {
	queue<int> q;
	q.push(n);
	subin[0][n] = 0;

	int time = 0;
	int nk = k;

	while (!q.empty()) {
		nk += time;
		if (nk >= KMAX)
			return;

		if (subin[time % 2][nk]) {
			minTime = time;
			return;
		}

		int qsize = q.size();
		while (qsize--) {
			int cur = q.front();
			q.pop();

			if (nk == cur) {
				minTime = time;
				return;
			}

			int next = cur - 1;
			if (next >= 0 && next < KMAX && !subin[(time + 1) % 2][next]) {
				q.push(next);
				subin[(time + 1) % 2][next] = true;
			}
			next = cur + 1;
			if (next >= 0 && next < KMAX && !subin[(time + 1) % 2][next]) {
				q.push(next);
				subin[(time + 1) % 2][next] = true;
			}
			next = cur * 2;
			if (next >= 0 && next < KMAX && !subin[(time + 1) % 2][next]) {
				q.push(next);
				subin[(time + 1) % 2][next] = true;
			}
		}
		time++;
	}
}

int main() {
	cin >> n >> k;

	init();
	moveSubin();

	cout << minTime << endl;
}