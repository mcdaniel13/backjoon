/*
 * https://www.acmicpc.net/problem/16935
 */

#include <iostream>
#include <vector>

using namespace std;

const int KMAX = 1000;
const int NMAX = 100;
int n, m, k;
int arr[KMAX];
int map[NMAX][NMAX];
int check[NMAX][NMAX];

void print(int curN, int curM) {
	for(int i = 0; i < curN; i++) {
		for(int j = 0; j < curM; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {
	int curN = n;
	int curM = m;
	for(int c = 0; c < k; c++) {
		int cur = arr[c];
		if(cur == 1) {
			for(int i = 0; i < curN; i++) {
				for(int j = 0; j < curM; j++) {
					check[i][j] = map[curN - 1 - i][j];
				}
			}
		} else if (cur == 2) {
			for(int i = 0; i < curM; i++) {
				for(int j = 0; j < curN; j++) {
					check[j][i] = map[j][curM - 1 - i];
				}
			}
		} else if (cur == 3) {
			int temp = curM;
			curM = curN;
			curN = temp;
			for(int i = 0; i < curN; i++) {
				for(int j = 0; j < curM; j++) {
					check[i][j] = map[curM - 1 - j][i];
				}
			}
		} else if (cur == 4) {
			int temp = curM;
			curM = curN;
			curN = temp;
			for(int i = 0; i < curN; i++) {
				for(int j = 0; j < curM; j++) {
					check[i][j] = map[j][curN - 1 - i];
				}
			}

		} else if (cur == 5) {
			for(int i = 0; i < curN / 2; i++) {
				for(int j = 0; j < curM / 2; j++) {
					check[i][j] = map[i + curN / 2][j];
				}
			}
			for(int i = 0; i < curN / 2; i++) {
				for (int j = curM / 2; j < curM; j++) {
					check[i][j] = map[i][j - curM / 2];
				}
			}
			for(int i = curN / 2; i < curN; i++) {
				for(int j = curM / 2; j < curM; j++) {
					check[i][j] = map[i - curN / 2][j];
				}
			}
			for(int i = curN / 2; i < curN; i++) {
				for(int j = 0; j < curM / 2; j++a) {
					check[i][j] = map[i][j + curM / 2];
				}
			}
		} else {
			for(int i = 0; i < curN / 2; i++) {
				for(int j = 0; j < curM / 2; j++) {
					check[i][j] = map[i][j + curM / 2];
				}
			}
			for(int i = 0; i < curN / 2; i++) {
				for (int j = curM / 2; j < curM; j++) {
					check[i][j] = map[i + curN / 2][j];
				}
			}
			for(int i = curN / 2; i < curN; i++) {
				for(int j = curM / 2; j < curM; j++) {
					check[i][j] = map[i][j - curM / 2];
				}
			}
			for(int i = curN / 2; i < curN; i++) {
				for(int j = 0; j < curM / 2; j++) {
					check[i][j] = map[i - curN / 2][j];
				}
			}
		}

		for(int i = 0; i < curN; i++) {
			for(int j = 0; j < curM; j++) {
				map[i][j] = check[i][j];
			}
		}
	}
	print(curN, curM);
}


int main() {
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for(int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	solve();
}