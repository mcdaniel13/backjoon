/*
	https://www.acmicpc.net/problem/16986
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX = 10;

int n, win;

int map[NMAX][NMAX];
int arr[20][3];
bool visit[NMAX];
int winCount[3];
int turnCount[3];
bool possible;

void init() {
	possible = false;

	for (int i = 1; i <= n; i++)
		visit[i] = false;

	for (int i = 0; i < 3; i++) {
		winCount[i] = 0;
		turnCount[i] = 0;
	}
}

int findWinner(int first, int second, int home, int away) {
	if (map[home][away] == 2)
		return first;
	else if (map[home][away] == 0)
		return second;
	else
		return max(first, second);
}

void solve(int first, int second, int round) {
	if (possible)
		return;

	if (winCount[0] == win) {
		possible = true;
		return;
	}

	if (winCount[1] == win || winCount[2] == win)
		return;

	int next = 3 - first - second;

	if (first == 0) {
		int away = arr[turnCount[second]][second];
		for (int i = 1; i <= n; i++) {
			if (possible)
				return;

			if (!visit[i]) {
				int winner = findWinner(first, second, i, away);
				winCount[winner]++;
				visit[i] = true;
				turnCount[second]++;

				solve(winner, next, round + 1);
				if (possible)
					return;

				winCount[winner]--;
				visit[i] = false;
				turnCount[second]--;
			}
		}
	}
	else if (second == 0) {
		int home = arr[turnCount[first]][first];
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) { //dfs
				int winner = findWinner(first, second, home, i);
				winCount[winner]++;
				visit[i] = true;
				turnCount[first]++;

				solve(winner, next, round + 1);
				if (possible)
					return;

				winCount[winner]--;
				visit[i] = false;
				turnCount[first]--;
			}
		}
	}
	else {
		int home = arr[turnCount[first]][first];
		int away = arr[turnCount[second]][second];
		int winner = findWinner(first, second, home, away);
		winCount[winner]++;
		turnCount[first]++;
		turnCount[second]++;

		solve(winner, next, round + 1);
		if (possible)
			return;

		winCount[winner]--;
		turnCount[first]--;
		turnCount[second]--;

	}
}

int main() {
	cin >> n >> win;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	for (int i = 0; i < 20; i++)
		cin >> arr[i][1];

	for (int i = 0; i < 20; i++)
		cin >> arr[i][2];

	init();
	solve(0, 1, 0);

	cout << possible << endl;
}