#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int NMAX = 21;

int arr[NMAX][NMAX];
bool team[NMAX];
int n;
int minDiff;

void print() {
	cout << "print" << endl;
	for (int i = 1; i <= n; i++) {
		cout << team[i] << " ";
	}
	cout << endl;
}

void calculatePoint() {
	int points[2] = { 0, 0 };
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (team[i] == true && team[j] == true) { // same team 1
				points[0] += arr[i][j];
				points[0] += arr[j][i];
			}
			else if (team[i] == false && team[j] == false) { // same team 2
				points[1] += arr[i][j];
				points[1] += arr[j][i];
			}
			else {
				continue;
			}
		}
	}
	//cout << "team 1 = " << points[0] << " team 2 = " << points[1] << endl;
	int diff = abs(points[0] - points[1]);
	//cout << "diff between team 1 & team 2 = " << diff << endl;
	minDiff = min(minDiff, diff);
}

void selectTeam(int cur, int cnt) {
	if (cnt == n / 2) {
		//print();
		calculatePoint();
		return;
	}

	for (int i = cur; i <= n; i++) {
		team[i] = true;
		selectTeam(i + 1, cnt + 1);
		team[i] = false;
	}
}

int main() {
	cin >> n;
	//init
	for (int i = 1; i <= n; i++) {
		team[i] = false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	minDiff = INT_MAX;
	selectTeam(1, 0);
	cout << minDiff << endl;
	//cout << endl;
}