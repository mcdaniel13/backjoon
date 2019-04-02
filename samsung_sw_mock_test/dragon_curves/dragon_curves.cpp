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
bool visit[NMAX][NMAX][20];
Dragon dragon[20];

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
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
		if (!visit[curY][curX][cur]) {
			map[curY][curX] += 1;
		}
		dir.push_back(curDir);
	}
	cout << "cur = " << curGen + 1 << endl;
	print();
	placeDragon(cur, curGen + 1, dir, curX, curY, gen);
}

void solve() {
	for (int i = 0; i < n; i++) {
		//init for gen = 0;
		vector<int> dir;
		int nextX = dragon[i].x + moving[dragon[i].start][0];
		int nextY = dragon[i].y + moving[dragon[i].start][1];
		map[dragon[i].y][dragon[i].x] += 1;
		map[nextY][nextX] += 1;
		cout << "init" << endl;
		print();
		visit[dragon[i].y][dragon[i].x][i] = true;
		dir.push_back(dragon[i].start);
		//find dragon at given gen
		if (dragon[i].gen > 0) {
			placeDragon(i, 0, dir, nextX, nextY, dragon[i].gen);
		}
		cout << "after" << endl;
		print();
	}

}

int main() {
	cin >> n;

	//init
	for (int i = 0; i < NMAX; i++) {
		for (int j = 0; j < NMAX; j++) {
			for (int k = 0; k < n; k++) {
				visit[i][j][k] = 0;
			}
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> dragon[i].x >> dragon[i].y >> dragon[i].start >> dragon[i].gen;
	}

	solve();

	cout << endl;
}