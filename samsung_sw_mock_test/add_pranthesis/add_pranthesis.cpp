/*
 * https://www.acmicpc.net/problem/16637
 */

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int NMAX = 19;

int n, ocnt, ncnt;

char oper[9];
long long num[10];
long long result;

long long calculate(long long a, long long b, char op) {
	long long result;
	if (op == '*')
		result = a * b;
	else if (op == '/')
		result = a / b;

	else if (op == '+')
		result = a + b;
	else
		result = a - b;
	return result;
}

void solve(long long cur, int operIndex) {
	if(operIndex == ocnt) {
		result = max(result, cur);
		return;
	}


	long long calculated = calculate(cur, num[operIndex + 1], oper[operIndex]);
	solve(calculated, operIndex + 1);

	if(operIndex + 2 < ncnt) {
		long long nextCalculated = calculate(num[operIndex + 1], num[operIndex + 2], oper[operIndex + 1]);
		calculated = calculate(cur, nextCalculated, oper[operIndex]);
		solve(calculated, operIndex + 2);
	}

}

int main() {
	cin >> n;

	ocnt = 0;
	ncnt = 0;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		if (temp - '0' >= 0 && temp - '0' <= 9) {
			num[ncnt] = temp - '0';
			ncnt++;
		}
		else {
			oper[ocnt] = temp;
			ocnt++;
		}
	}

	result = LLONG_MIN;
	solve(num[0], 0);
	cout << result << endl;
}
