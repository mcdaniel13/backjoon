#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 11;
const int HMAX = 31;

int map[HMAX][NMAX];

int n, m, h;

int result;

void print() {
	for (int i = 0; i <= h; i++) {	//height
		for (int j = 0; j <= n; j++) {	//line
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int solve() {
	int matchCount = 0;
	for (int i = 1; i <= n; i++) {
		int curLine = i;
		int height = 1;
		while (height < h)
			if (map[height][curLine] == 1) {	// move down
				height++;
			}
			else if (map[height][curLine] == 2) {	// move right
				curLine++;
				height++;
			}
			else if (map[height][curLine] == 3) {	// move left
				curLine--;
				height++;
			}
		cout << "start = " << i << " end = " << curLine << endl;;
		if (curLine == i) {
			matchCount++;
		}
	}

	cout << "matchCount = " << matchCount << endl;
	return matchCount;
	//	if (matchCount == n) {
	//
	//	}
}

void selectCross(int cur, int curLine, int curHeight) {
	if (cur == 3 || cur > result) {
		return;
	}

	int matchCount = solve();	// no additional crossline;
	if (matchCount == n) {
		result = 0;
	}
	else {
		for (int i = curLine; i <= n; i++) {
			for (int j = curHeight; j <= h; j++) {
				if (map[j][i] == 1 && map[j][i] == 1) {	// check available spot to put crossline
					map[j][i] = 2;
					map[j][i + 1] = 3;
					cout << "====crossLine added @" << i << "<->" << i + 1 << " at height = " << j << " ====" << endl;
					matchCount = solve();
					if (matchCount == n) {
						result = min(result, matchCount);
					}
					else {
						selectCross(cur + 1, curLine, cu);
					}
					cout << "====crossLine deleted @" << i << "<->" << i + 1 << " ====" << endl;
					map[j][i] = 1;
					map[j][i + 1] = 1;
				}
			}
		}
	}
}


int main() {
	cin >> n >> m >> h;

	//init
	for (int i = 1; i <= h; i++) {	//height
		for (int j = 1; j <= n; j++) {	//line
			map[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		int height, line;
		cin >> height >> line;
		map[height][line] = 2;	//go left
		map[height][line + 1] = 3;	//go right;
	}

	print();

	result = 4;

	selectCross(0);

	if (result == 4) {
		result = -1;
	}

	cout << result << endl;
	cout << endl;
}