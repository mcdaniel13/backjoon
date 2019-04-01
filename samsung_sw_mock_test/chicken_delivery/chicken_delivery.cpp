/*
 * https://www.acmicpc.net/problem/15686
 */
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int NMAX = 50;

int n, m;
int map[NMAX][NMAX];
int house[NMAX][2];
int chicken[NMAX][2];
bool cVisited[NMAX];
int hCount;
int cCount;
int minDistance;

void dfs(int curCount, int selectedCount) {
    if(selectedCount == m) {
        int totalDist = 0;
        for(int j = 0; j < hCount; j++) {
            int minDist = INT_MAX;
            for(int i = 0; i < cCount; i++) {
                if(cVisited[i]) {
                    int tempDist = abs(chicken[i][0] - house[j][0]) + abs(chicken[i][1] - house[j][1]);
                    minDist = min(minDist, tempDist);
                }
            }
            totalDist += minDist;
        }
        minDistance = min(minDistance, totalDist);
    }

    if(curCount == cCount)
        return;

    cVisited[curCount] = true;
    dfs(curCount + 1, selectedCount + 1);
    cVisited[curCount] = false;
    dfs(curCount + 1, selectedCount);
}

void solve() {
    //init
    minDistance = INT_MAX;
    for(int i = 0; i < cCount; i++)
        cVisited[i] = false;

    dfs(0, 0);
}
int main() {
    cin >> n >> m;
    hCount = 0; cCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                house[hCount][0] = i;
                house[hCount][1] = j;
                hCount++;
            } else if(map[i][j] == 2) {
                chicken[cCount][0] = i;
                chicken[cCount][1] = j;
                cCount++;
            }
        }
    }
    solve();

    cout << minDistance << endl;
}