/*
 * https://www.acmicpc.net/problem/14501
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 30;

int n;

int arr[NMAX];
int input[NMAX][2];
int main() {
    cin >> n;

    for (int i = 0; i < NMAX; i++)
        arr[i] = 0;

    for (int i = 0; i < n; i++)
        cin >> input[i][0] >> input[i][1];

    int prev = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = max(prev, arr[i]);
        arr[i + input[i][0] - 1] = max(arr[i + input[i][0] - 1], prev + input[i][1]);
        prev = arr[i];
    }

    cout << arr[n - 1] << endl;
}