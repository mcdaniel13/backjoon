/* https://www.acmicpc.net/problem/16939
*/

#include <iostream>
#include <vector>

using namespace std;

void clockwise(vector<vector<int>> &side) {
	int temp = side[0][0];
	side[0][0] = side[1][0];
	side[1][0] = side[1][1];
	side[1][1] = side[0][1];
	side[0][1] = temp;
}

void U(vector<vector<vector<int>>> &cube) {
	vector<vector<int>> temp = cube[1];
	for (int i = 0; i < 2; i++) {
		//first row
		//front <- right <- back <- left
		cube[1][0][i] = cube[4][0][i];
		cube[4][0][i] = cube[5][0][i];
		cube[5][0][i] = cube[3][0][i];
		cube[3][0][i] = temp[0][i];
	}

	//up - clockwise rotate
	clockwise(cube[0]);
}

void D(vector<vector<vector<int>>> &cube) {
	vector<vector<int>> temp = cube[1];
	for (int i = 0; i < 2; i++) {
		//second row
		// front <- left <- back <- right
		cube[1][1][i] = cube[3][1][i];
		cube[3][1][i] = cube[5][1][i];
		cube[5][1][i] = cube[4][1][i];
		cube[4][1][i] = temp[1][i];
	}

	//down - clockwise rotate
	clockwise(cube[2]);
}

bool check(const vector<vector<vector<int>>> &cube) {
	for (int i = 0; i < 6; i++) {
		int compare = cube[i][0][0];
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if (cube[i][j][k] != compare)
					return false;
			}
		}
	}
	return true;
}

bool solve(vector<vector<vector<int>>> &copied) {

	vector<vector<vector<int>>> cube = copied;
	U(cube);
	if (check(cube))
		return true;
	U(cube);
	U(cube);
	if (check(cube))
		return true;
	U(cube);

	D(cube);
	if (check(cube))
		return true;
	D(cube); D(cube);
	if (check(cube))
		return true;
	D(cube);

	//roll front
	vector<vector<int>> temp1 = cube[0];
	cube[0] = cube[5];
	cube[5] = cube[2];
	cube[2] = cube[1];
	cube[1] = temp1;

	clockwise(cube[5]);	clockwise(cube[5]);
	clockwise(cube[0]);	clockwise(cube[0]);
	clockwise(cube[3]);
	clockwise(cube[4]);	clockwise(cube[4]);	clockwise(cube[4]);

	U(cube);
	if (check(cube))
		return true;
	U(cube);
	U(cube);
	if (check(cube))
		return true;
	U(cube);

	D(cube);
	if (check(cube))
		return true;
	D(cube); D(cube);
	if (check(cube))
		return true;
	D(cube);


	cube = copied;

	//roll right
	vector<vector<int>> temp2 = cube[0];
	cube[0] = cube[4];
	cube[4] = cube[2];
	cube[2] = cube[3];
	cube[3] = temp2;

	clockwise(cube[0]); clockwise(cube[0]); clockwise(cube[0]);
	clockwise(cube[1]);	clockwise(cube[1]);	clockwise(cube[1]);
	clockwise(cube[2]); clockwise(cube[2]); clockwise(cube[2]);
	clockwise(cube[3]); clockwise(cube[3]);	clockwise(cube[3]);
	clockwise(cube[4]);	clockwise(cube[4]);	clockwise(cube[4]);
	clockwise(cube[5]);

	U(cube);
	if (check(cube))
		return true;
	U(cube);
	U(cube);
	if (check(cube))
		return true;
	U(cube);

	D(cube);
	if (check(cube))
		return true;
	D(cube);
	D(cube);
	if (check(cube))
		return true;
	D(cube);

	return false;
}

int main() {
	vector<vector<vector<int>>> cube(6, vector<vector<int>>(2, vector<int>(2)));	//up, front, down, right, left, back;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> cube[i][j][k];
			}
		}
	}

	cout << solve(cube);
	cout << endl;
}