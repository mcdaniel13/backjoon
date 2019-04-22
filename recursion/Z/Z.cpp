/*
 * https://www.acmicpc.net/problem/1074
 */

#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;
int maxn, cnt;
int moving[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

void solve(int n, int r, int c) {
	if(n == 2) {
		for(int i = 0; i < 4; i++) {
			int nr = r + moving[i][0];
			int nc = c + moving[i][1];
			if(nr == R && nc == C) {
				cout << cnt << endl;
				break;
			}
			cnt++;
		}
		return;
	}

	solve(n / 2, r, c);
	solve(n / 2, r, c + n / 2);
	solve(n / 2, r + n / 2, c);
	solve(n / 2, r + n / 2, c + n /2);
}

int main() {
	cin >> N >> R >> C;

	R = R + 1;
	C = C + 1;
	cnt = 0;
	maxn = pow(2, N);
	solve(maxn, 1, 1);
}