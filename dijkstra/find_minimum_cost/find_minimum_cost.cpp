/*
 * https://www.acmicpc.net/problem/1916
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 1001;
const int MMAX = 1000000;
const int INF = 10e9;

int n, m, start_point, end_point;

int dist[NMAX];
vector<pair<int,int>> edge[NMAX];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(dist[current] < distance)
            continue;
        for(int i = 0; i < edge[current].size(); i++) {
            int next = edge[current][i].second;
            int nextDistance = edge[current][i].first + distance;
            if(nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].push_back(make_pair(cost, to));
    }

    cin >> start_point >> end_point;

    //init
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    dijkstra(start_point);

    cout << dist[end_point] << endl;
}