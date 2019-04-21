/*
 *  https://www.acmicpc.net/problem/11657
 */

#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 501;
const int INF = 1e9;

int n, m;

vector<pair<int,int>> edges[NMAX];
int dist[NMAX];

void print() {
    for(int i = 2; i <= n; i++) {
        cout << (dist[i] != INF ? dist[i] : -1) << endl;
    }
}

bool bellmanFord() {
    dist[1] = 0;
    bool isCycle = false;
    // 모든 노드의 수 - 1 만큼
    for (int k = 0; k < n; k++) {
        // 모든 노드
        for (int i = 1; i <= n; i++) {
            // 모든 엣지
            for(int j = 0; j < edges[i].size(); j++) {
                int next = edges[i][j].first;
                int nextDistance = edges[i][j].second;
                if(dist[i] != INF && dist[next] > dist[i] + nextDistance) {
                    dist[next] = dist[i] + nextDistance;
                    if(k == n - 1)
                        isCycle = true;
                }
            }
        }
    }

    return isCycle;
}
int main() {
    cin >> n >> m;
    //init
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    //get input
    for(int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back(make_pair(to, dist));
    }

    if(bellmanFord())
        cout << "-1" << endl;
    else
        print();
}
