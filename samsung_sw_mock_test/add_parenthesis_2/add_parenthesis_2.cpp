/*
 * https://www.acmicpc.net/problem/16638
 */

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>


using namespace std;

const int NMAX = 19;

int n;

bool parenthesis[NMAX];
char arr[NMAX];
long long result;

long long calculate_internal(long long a, long long b, char op) {
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

long long calculate() {
	vector<long long> tempNum;
	vector<char> tempOper;
	for(int i = 0; i < n; i++) {
		if(arr[i] - '0' >= 0 && arr[i] - '0' <= 9) {
			if (parenthesis[i]) {
				long long a = arr[i] - '0';
				long long b = arr[i + 2] - '0';
				long long res = calculate_internal(a, b, arr[i + 1]);
				tempNum.push_back(res);
				i += 2;
			} else
				tempNum.push_back(arr[i] - '0');
		} else
			tempOper.push_back(arr[i]);
	}

	vector<long long> tempNum2;
	vector<char> tempOper2;
	tempNum2.push_back(tempNum[0]);
	for(int i = 0; i < tempOper.size(); i++) {
		if(tempOper[i] ==  '*') {
			long long a = tempNum2[tempNum2.size() - 1];
			long long b = tempNum[i + 1];
			long long temp = a * b;
			tempNum2.pop_back();
			tempNum2.push_back(temp);
		} else {
			tempNum2.push_back(tempNum[i + 1]);
			tempOper2.push_back(tempOper[i]);
		}
	}

	if(tempNum2.size() == 1)
		return tempNum2[0];
	else {
		long long res = tempNum2[0];
		for(int i = 0; i < tempOper2.size(); i++) {
			res = calculate_internal(res, tempNum2[i + 1], tempOper2[i]);
		}
		return res;
	}
}

void solve(int index) {
	if(index == n) {
		long long res = calculate();
		result = max(res, result);
		return;
	}

	for(int i = index; i < n; i += 2) {
		if(arr[i] - '0' >= 0 && arr[i] - '0' <= 9) {
			if(i + 2 < n && !parenthesis[i] && !parenthesis[i + 2]) {
				parenthesis[i] = true;
				parenthesis[i + 2] = true;
				solve(i + 2);
				parenthesis[i] = false;
				parenthesis[i + 2] = false;
			} else {
				solve(i + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	result = LLONG_MIN;
	for(int i = 0; i < NMAX; i++)
		parenthesis[i] = false;

	solve(0);
	cout << result << endl;
}
