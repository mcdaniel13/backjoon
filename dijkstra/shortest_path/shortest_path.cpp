/*
 * https://www.acmicpc.net/problem/1753
 */

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int NMAX = 20001;
int n, m, start, from, to, weight;

vector<pair<int,int>> nodes[NMAX];     //store destination and weight;
int dist[NMAX];

struct compare {
    bool operator()(pair<int, int> one, pair<int, int> two) {
        return one.first < two.first;
    }
};

void dijkstra() {
    dist[start] = 0;
//    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int current = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(dist[current] < weight)
            continue;
        for(int i = 0; i < nodes[current].size();i++) {
            int next = nodes[current][i].first;
            int nextWeight = nodes[current][i].second + weight;
            if(nextWeight < dist[next]) {
                dist[next] = nextWeight;
                pq.push(make_pair(-nextWeight, next));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d", &start);

    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        nodes[from].push_back(make_pair(to, weight));
    }

    dijkstra();

    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}