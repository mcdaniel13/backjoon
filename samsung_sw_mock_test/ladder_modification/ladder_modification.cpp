/* https://www.acmicpc.net/problem/15684 */

#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 11;
const int HMAX = 31;

int map[HMAX][NMAX];
int cross[NMAX * HMAX][2];
int n, m, h;
int crossCount;

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
		while (height <= h)
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
		//		cout << "start = " << i << " end = " << curLine << endl;;
		if (curLine == i) {
			matchCount++;
		}
	}

	//	cout << "matchCount = " << matchCount << endl;
	return matchCount;
	//	if (matchCount == n) {
	//
	//	}
}

void selectCross() {
	if (solve() == n) {
		result = 0;
		return;
	}
	//single
	for (int i = 0; i < crossCount; i++) {
		int curHeight = cross[i][0];
		int curLine = cross[i][1];
		map[curHeight][curLine] = 2;
		map[curHeight][curLine + 1] = 3;
		//		print();
		if (solve() == n) {
			result = 1;
			return;
		}
		map[curHeight][curLine] = 1;
		map[curHeight][curLine + 1] = 1;
	}

	for (int i = 0; i < crossCount; i++) {
		int curHeight = cross[i][0];
		int curLine = cross[i][1];
		map[curHeight][curLine] = 2;
		map[curHeight][curLine + 1] = 3;
		for (int j = i + 1; j < crossCount; j++) {
			int nextHeight = cross[j][0];
			int nextLine = cross[j][1];
			if (map[nextHeight][nextLine] == 1 && map[nextHeight][nextLine + 1] == 1) {
				map[nextHeight][nextLine] = 2;
				map[nextHeight][nextLine + 1] = 3;
				//				print();
				if (solve() == n) {
					result = 2;
					return;
				}
				map[nextHeight][nextLine] = 1;
				map[nextHeight][nextLine + 1] = 1;
			}
		}
		map[curHeight][curLine] = 1;
		map[curHeight][curLine + 1] = 1;
	}

	for (int i = 0; i < crossCount; i++) {
		int curHeight = cross[i][0];
		int curLine = cross[i][1];
		map[curHeight][curLine] = 2;
		map[curHeight][curLine + 1] = 3;
		for (int j = i + 1; j < crossCount; j++) {
			int nextHeight = cross[j][0];
			int nextLine = cross[j][1];
			if (map[nextHeight][nextLine] == 1 && map[nextHeight][nextLine + 1] == 1) {
				map[nextHeight][nextLine] = 2;
				map[nextHeight][nextLine + 1] = 3;
				for (int k = j + 1; k < crossCount; k++) {
					int thirdHeight = cross[k][0];
					int thirdLine = cross[k][1];
					if (map[thirdHeight][thirdLine] == 1 && map[thirdHeight][thirdLine + 1] == 1) {
						map[thirdHeight][thirdLine] = 2;
						map[thirdHeight][thirdLine + 1] = 3;
						//						print();
						if (solve() == n) {
							result = 3;
							return;
						}
						map[thirdHeight][thirdLine] = 1;
						map[thirdHeight][thirdLine + 1] = 1;
					}
				}
				map[nextHeight][nextLine] = 1;
				map[nextHeight][nextLine + 1] = 1;
			}
		}
		map[curHeight][curLine] = 1;
		map[curHeight][curLine + 1] = 1;
	}

}

void findCrosslineSpot() {
	crossCount = 0;
	for (int i = 1; i <= h; i++) {	//height
		for (int j = 1; j < n; j++) {	//line
			if (map[i][j] == 1 && map[i][j + 1] == 1) {
				cross[crossCount][0] = i;
				cross[crossCount][1] = j;
				crossCount++;
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

	//	print();

	findCrosslineSpot();

	result = -1;
	selectCross();

	cout << result << endl;
	cout << endl;
}