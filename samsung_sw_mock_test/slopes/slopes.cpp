/*
 * https://www.acmicpc.net/problem/14890
 */
#include <iostream>

using namespace std;

const int NMAX = 100;

int n, l;

int map[NMAX][NMAX];

int totalCount;

void rowCount(){
    for (int i = 0; i < n; i++) {
        //cout << "==== curRow = " << i + 1 << " ==== " << endl;
        int cur = map[i][0];
        int cnt = 1;
        bool isPossible = true;
        for (int j = 1; j < n; j++) {
            int next = map[i][j];
            if (next == cur)
                cnt++;
            else if (next - 1 == cur) {	//bigger
                if (cnt < l) {
                    isPossible = false;
                    break;
                }
                else {
                    cur = next;
                    cnt = 1;
                }

            }
            else if (next + 1 == cur) {
                cur = next;
                cnt = 0;
                for (int k = j; k < n; k++) {
                    j = k;
                    if (map[i][k] == cur) {
                        cnt++;
                        if (cnt == l) {
                            break;
                        }
                        if (cnt != l && k == n - 1) {
                            isPossible = false;
                            break;
                        }
                    }
                    else {
                        isPossible = false;
                        break;
                    }
                }
                cnt = 0;
            }
            else {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            totalCount++;
            //cout << "Possible : totalCount = " << totalCount << endl;

        }
        //else {
        //	cout << "not Possible : totalCount = " << totalCount << endl;
        //}
    }
}

void colCount() {
    for (int i = 0; i < n; i++) {
        //cout << "==== curCol = " << i + 1 << " ==== " << endl;
        int cur = map[0][i];
        int cnt = 1;
        bool isPossible = true;
        for (int j = 1; j < n; j++) {
            int next = map[j][i];
            if (next == cur)
                cnt++;
            else if (next - 1 == cur) {	//bigger
                if (cnt < l) {
                    isPossible = false;
                    break;
                }
                else {
                    cur = next;
                    cnt = 1;
                }

            }
            else if (next + 1 == cur) {
                cur = next;
                cnt = 0;
                for (int k = j; k < n; k++) {
                    j = k;
                    if (map[k][i] == cur) {
                        cnt++;
                        if (cnt == l) {
                            break;
                        }
                        if (cnt != l && k == n - 1) {
                            isPossible = false;
                            break;
                        }
                    }
                    else {
                        isPossible = false;
                        break;
                    }
                }

                cnt = 0;
            }
            else {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            totalCount++;
            //cout << "Possible : totalCount = " << totalCount << endl;

        }
        //else {
        //	cout << "not Possible : totalCount = " << totalCount << endl;
        //}
    }
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    totalCount = 0;
    rowCount();
    colCount();

    cout << totalCount << endl;
}