/*
	https://www.acmicpc.net/problem/16928
*/

#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int NMAX = 101;

int n, m;
int moving[NMAX];
int cnt[NMAX];

struct step {
	int x;
	int s;
	step(int x_, int s_) {
		x = x_;
		s = s_;
	}
};

void solve() {
	queue<step> q;
	q.push(step(1, 0));

	while (!q.empty()) {
		step cur = q.front();
		q.pop();
		//cout << "==== cur = " << cur.x << " steps = " << cur.s << " ====" << endl;
		if (moving[cur.x] > 0) {
			int nx = moving[cur.x];
			int ncnt = cur.s;
			if (nx >= 0 && nx < NMAX && cnt[nx] > ncnt) {
				//cout << "next step = " << nx << " steps = " << ncnt << endl;
				cnt[nx] = ncnt;
				q.push(step(nx, ncnt));
			}
		}
		else {
			for (int i = 1; i <= 6; i++) {
				int nx = cur.x + i;
				int ncnt = cur.s + 1;
				if (nx >= 0 && nx < NMAX && cnt[nx] > ncnt) {
					//cout << "next step = " << nx << " steps = " << ncnt << endl;
					cnt[nx] = ncnt;
					q.push(step(nx, ncnt));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < NMAX; i++) {
		moving[i] = 0;
		cnt[i] = INT_MAX;
	}

	for (int i = 0; i < n + m; i++) {
		int start, end;
		cin >> start >> end;
		moving[start] = end;
	}

	solve();
	cout << cnt[100] << endl;
}