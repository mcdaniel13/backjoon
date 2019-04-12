#include <iostream>

using namespace std;

const int NMAX = 19;

int n, ocnt, ncnt;

char oper[9];
long long num[10];

long long calculate(int a, int b, char op) {
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

	int calculated = calculate(cur, num[operIndex + 1], operIndex);
	solve(calculated, operIndex + 1);


}

int main() {
	cin >> n;

	ocnt = 0;
	ncnt = 0;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		if (temp - '0' >= 1 && temp - '0' <= 9) {
			num[ncnt] = temp - '0';
			ncnt++;
		}
		else {
			oper[ocnt] = temp;
			ocnt++;
		}
	}

	solve(0, false, 0, 0);
}