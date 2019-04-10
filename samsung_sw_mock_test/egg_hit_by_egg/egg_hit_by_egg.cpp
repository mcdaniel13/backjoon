/*
	https://www.acmicpc.net/problem/16987
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 8;

int n;

int eggs[NMAX][2];	// hp, weight
int after[NMAX];
bool broken[NMAX];
int maxCount;

void solve(int cur, int cnt) {
	if (cur == n) {
		maxCount = max(maxCount, cnt);
		return;
	}

	if (broken[cur]) {
		solve(cur + 1, cnt);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (cur == i)
				continue;

			if (broken[i])
				continue;

			int curCount = 0;
			eggs[i][0] -= eggs[cur][1];
			eggs[cur][0] -= eggs[i][1];
			if (eggs[i][0] <= 0) {
				broken[i] = true;
				curCount++;
			}

			if (eggs[cur][0] <= 0) {
				broken[cur] = true;
				curCount++;
			}

			solve(cur + 1, cnt + curCount);

			if (eggs[i][0] <= 0) {
				broken[i] = false;
			}

			if (eggs[cur][0] <= 0) {
				broken[cur] = false;
			}

			eggs[i][0] += eggs[cur][1];
			eggs[cur][0] += eggs[i][1];
		}
	}
	maxCount = max(maxCount, cnt);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> eggs[i][0] >> eggs[i][1];
	}

	//init()
	for (int i = 0; i < n; i++) {
		broken[i] = false;
	}

	maxCount = 0;
	solve(0, 0);
	cout << maxCount << endl;
}