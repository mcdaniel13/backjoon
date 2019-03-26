/*
 * https://www.acmicpc.net/problem/16236
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int NMAX = 20;

int moving[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int n;

int arr[NMAX][NMAX];
bool visited[NMAX][NMAX];

int sharkX;
int sharkY;
int sharkSize;

int totalFish;

int totalDistance;

pair<int, pair<int,int>> bfs() {
    queue<pair<int, pair<int,int>>> q;
    vector<pair<int, pair<int,int>>> eatenFish;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    q.push(make_pair(0, make_pair(sharkX, sharkY)));

    while(!q.empty()) {
        int prevX = q.front().second.first;
        int prevY = q.front().second.second;
        int prevDist = q.front().first;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int newX = prevX + moving[i][0];
            int newY = prevY + moving[i][1];
            if(newX >=0 && newX < n && newY >= 0 && newY < n) {
                if(!visited[newX][newY] && arr[newX][newY] <= sharkSize) {
                    int newDist = prevDist + 1;
                    visited[newX][newY] = true;
                    if (arr[newX][newY] < sharkSize && arr[newX][newY] != 0)
                        eatenFish.push_back(make_pair(newDist, make_pair(newX, newY)));
                    q.push(make_pair(newDist, make_pair(newX, newY)));
                }
            }
        }
    }

    if(eatenFish.size() == 0)
        return make_pair(-1, make_pair(-1, -1));
    else {
        sort(eatenFish.begin(), eatenFish.end());
        return eatenFish[0];
    }
}


void solve() {
    sharkSize = 2;
    arr[sharkX][sharkY] = 0;
    totalDistance = 0;

    int eatCount = 0;
    int totalEatCount = 0;

    while(totalEatCount < totalFish) {
        pair<int, pair<int, int>> next = bfs();
        if(next.first < 0)
            break;
        else {
            sharkX = next.second.first;
            sharkY = next.second.second;
            totalDistance += next.first;
            arr[sharkX][sharkY] = 0;
            eatCount++;
            totalEatCount++;
        }

        if(eatCount == sharkSize) {
            sharkSize++;
            eatCount = 0;
        }
    }
}

int main() {
    cin >> n;
    totalFish = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                sharkX = i;
                sharkY = j;
            } else if (arr[i][j] != 0)
                totalFish++;
        }
    }

    solve();

    cout << totalDistance << endl;
}