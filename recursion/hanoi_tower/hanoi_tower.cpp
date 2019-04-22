/*
 * https://www.acmicpc.net/problem/1914
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if(n == 1) {
		printf("%d %d\n", from, to);
	} else {
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	char result[10000000];
	long double cnt = pow(2, n);

	sprintf(result, "%.0Lf",cnt);
	int size = strlen(result);
	result[size - 1] = (char)(((int)(result[size - 1] - 48) - 1) + 48);
	printf("%s\n", result);

	if (n <= 20) {
		hanoi(n, 1, 2, 3);
	}
	return 0;
}