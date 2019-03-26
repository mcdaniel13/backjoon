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

int numOfFish;
int totalDistance;

pair<int, pair<int,int>> bfs() {
    queue<pair<int, pair<int,int>>> q;
    vector<pair<int, pair<int,int>>> eatenFish;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    visited[sharkX][sharkY] = true;

    q.push(make_pair(0, make_pair(sharkX, sharkY)));

    while(!q.empty()) {
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        int curDist = q.front().first;

        q.pop();

        for(int i = 0; i< 4; i++) {
            int newX = curX + moving[i][0];
            int newY = curY + moving[i][1];
            if(newX >= 0 && newX < n && newY >=0 && newY < n) {
                if(!visited[newX][newY] && arr[newX][newY] <= sharkSize) {
                    int newDist = curDist + 1;
                    if (arr[newX][newY] < sharkSize && arr[newX][newY] != 0) {
                        eatenFish.push_back(make_pair(newDist, make_pair(newX, newY)));
                    }
                    visited[newX][newY] = true;
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

    int eatCount = 0;
    int totalEatCount = 0;

    while(totalEatCount < numOfFish) {
        pair<int, pair<int,int>> next = bfs();
        if (next.first == -1)
            break;
        else {
            eatCount++;
            totalEatCount++;
            sharkX = next.second.first;
            sharkY = next.second.second;
            arr[sharkX][sharkY] = 0;
            totalDistance += next.first;
        }

        if(eatCount == sharkSize) {
            sharkSize++;
            eatCount = 0;
        }
    }
}

int main() {
    cin >> n;
    numOfFish = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                sharkX = i;
                sharkY = j;
                arr[i][j] = 0;
            } else if (arr[i][j] != 0) {
                numOfFish++;
            }
        }
    }

    totalDistance = 0;
    solve();

    cout << totalDistance << endl;
}