/*
 * https://www.acmicpc.net/problem/16922
 */

#include <iostream>

using namespace std;

int n;
int arr[4];
int num[4] = {1, 5, 10 ,50};
bool visit[1001];

void init() {
	for(int i = 0; i < 4; i++) {
		arr[i] = 0;
	}

	for(int i = 0; i < 1001; i++) {
		visit[i] = false;
	}
}

void calculate() {
	int total = 0;
	for(int i = 0; i < 4; i ++) {
		total += arr[i] * num[i];
	}
	visit[total] = true;
}

void solve(int cur, int num) {
	if(cur == 3) {
		arr[3] = num;
		calculate();
		return;
	}

	for(int i = 0; i <= num; i++) {
		arr[cur] = i;
		solve(cur + 1, num - i);
	}
}

int counting() {
	int cnt = 0;
	for(int i = 0; i < 1001; i++) {
		if(visit[i])
			cnt++;
	}
	return cnt;
}

int main() {

	cin >> n;

	init();
	solve(0, n);
	cout << counting() << endl;

}