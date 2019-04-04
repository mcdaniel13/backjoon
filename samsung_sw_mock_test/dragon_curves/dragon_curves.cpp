#include <iostream>
#include <vector>
using namespace std;

const int NMAX = 101;

int n;
int moving[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

struct Dragon {
	int x;	//col
	int y;	//row
	int start;
	int gen;
};

int map[NMAX][NMAX];
Dragon dragon[20];

int squareCount;

void findSquare() {
	for(int i = 0; i < NMAX - 1; i++) {
		for(int j = 0; j < NMAX - 1; j++) {
			if(map[i][j] != 0 && map[i + 1][j] != 0 && map[i + 1][j + 1] != 0 && map[i][j + 1] != 0)
				squareCount++;
		}
	}
}

void placeDragon(int cur, int curGen, vector<int> &dir, int x, int y, int gen) {
	if (curGen == gen)
		return;

	int curX = x;
	int curY = y;
	int end = dir.size();
	for (int i = end - 1; i >= 0; i--) {
		int curDir = (dir[i] + 1) % 4;
		curX += moving[curDir][0];
		curY += moving[curDir][1];
		map[curY][curX] += 1;
		dir.push_back(curDir);
	}
	placeDragon(cur, curGen + 1, dir, curX, curY, gen);
}

void solve() {
	for (int i = 0; i < n; i++) {
		vector<int> dir;    // save dragon direction at gen;

		//init for gen = 0;
		int nextX = dragon[i].x + moving[dragon[i].start][0];
		int nextY = dragon[i].y + moving[dragon[i].start][1];
		map[dragon[i].y][dragon[i].x] += 1;
		map[nextY][nextX] += 1;
		dir.push_back(dragon[i].start);

		//find dragon at given gen
		if (dragon[i].gen > 0)
			placeDragon(i, 0, dir, nextX, nextY, dragon[i].gen);
	}

	// find square
	squareCount = 0;
	findSquare();
}

int main() {
	cin >> n;

	//init
	for (int i = 0; i < NMAX; i++)
		for (int j = 0; j < NMAX; j++)
			map[i][j] = 0;

	//input
	for (int i = 0; i < n; i++)
		cin >> dragon[i].x >> dragon[i].y >> dragon[i].start >> dragon[i].gen;

	solve();

	cout << squareCount << endl;
}