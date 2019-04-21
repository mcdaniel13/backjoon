/*
 * https://www.acmicpc.net/problem/2606
 */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int NMAX = 101;

int n, m;

vector<vector<int>> computer(NMAX, vector<int>(NMAX, INF));
int dist[NMAX][NMAX];

void init() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dist[i][j] = computer[i][j];
}

void floydWarshall() {
    //거쳐가는 노드
    for(int k = 1; k <= n; k++) {
        //출발 노드
        for(int i = 1; i <= n; i++) {
            //도착 노드
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int calculate() {
    int sum = 0;
    for(int i = 2; i <= n; i++) {
        if(dist[1][i] < INF)
            sum++;
    }
    return sum;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int to, from;
        cin >> to >> from;
        computer[to][from] = 1;
        computer[from][to] = 1;
    }

    init();
    floydWarshall();
    cout << calculate() << endl;
}