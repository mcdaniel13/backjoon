/*
 * https://www.acmicpc.net/problem/14888
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int NMAX = 11;

int num[NMAX];
char arr[NMAX - 1];

int add;
int substract;
int multiply;
int divide;

int n;

int minVal;
int maxVal;

void print() {
	cout << "print" << endl;
	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void solve() {
	int cur = 1;
	int curVal = num[0];
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == '+') {
			curVal += num[cur];
		}
		else if (arr[i] == '-') {
			curVal -= num[cur];
		}
		else if (arr[i] == '*') {
			curVal *= num[cur];
		}
		else {
			curVal /= num[cur];
		}
		cur++;
	}
	//cout << "val = " << curVal << endl;
	minVal = min(minVal, curVal);
	maxVal = max(maxVal, curVal);
}

void setArr(int cur) {
	if (cur == n - 1) {
		//print();
		solve();
		return;
	}

	if (add > 0) {
		arr[cur] = '+';
		add--;
		setArr(cur + 1);
		add++;
	}
	if (substract > 0) {
		arr[cur] = '-';
		substract--;
		setArr(cur + 1);
		substract++;
	}
	if (multiply > 0) {
		arr[cur] = '*';
		multiply--;
		setArr(cur + 1);
		multiply++;
	}
	if (divide > 0) {
		arr[cur] = '/';
		divide--;
		setArr(cur + 1);
		divide++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	cin >> add >> substract >> multiply >> divide;

	minVal = INT_MAX;
	maxVal = INT_MIN;
	setArr(0);
	cout << maxVal << endl;
	cout << minVal << endl;
}