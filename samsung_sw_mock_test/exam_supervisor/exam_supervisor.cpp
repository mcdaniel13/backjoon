/*
 * https://www.acmicpc.net/problem/13458
 */

#include <iostream>
#include <cmath>

using namespace std;

const int NMAX = 1000000;
double arr[NMAX];

int n;
double b, c;

void solve() {
	long total = 0;
	for (int i = 0; i < n; i++) {
		//cout << "===== round #" << i + 1 << " =====" << endl;
		double val = arr[i] - b;
		total++;

		//cout << "val = " << val << " val / c = " << val / c << endl;
		if(val > 0)
			total += ceil(val / c);
		//cout << "total = " << ceil(val / c) << endl;
	}
	cout << total << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	solve();
	cout << endl;
}