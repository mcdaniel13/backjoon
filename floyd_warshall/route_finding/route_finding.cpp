/*
 * https://www.acmicpc.net/problem/11403
 */

#include <iostream>

using namespace std;

const int NMAX = 101;
const int INF = 1000;

int n;
int dist[NMAX][NMAX];

void floydWarshall() {
    //거쳐가는 노드 O(n)
    for(int k = 1; k <= n; k++) {
        //시작 노드 O(n)
        for(int i = 1; i <= n; i++) {
            //도착 노드 O(n)
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
            if (!dist[i][j])
                dist[i][j] = INF;
        }
    }

    floydWarshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(dist[i][j] >= INF)
                cout << "0" << " ";
            else
                cout << "1" << " ";
        }
        cout << endl;
    }
}