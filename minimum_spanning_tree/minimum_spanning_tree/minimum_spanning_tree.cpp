/*
 * https://www.acmicpc.net/problem/1197
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NMAX = 100001;

int parent[NMAX];
int ranks[NMAX];

struct edge {
    int to;
    int from;
    int cost;
    edge() {}
//    edge(int to_, int from_, int cost_) {
//        to = to_;
//        from = from_;
//        cost = cost_;
//    }
};

bool compare(edge one, edge two) {
    return one.cost < two.cost;
}

int find(int u) {
    if(parent[u] == u)
        return u;
    else
        return parent[u] = find(parent[u]);
}

void merge(int a, int b) {
    int u = find(a);
    int v = find(b);

    if(ranks[u] > ranks[v])
        parent[v] = u;
    else if (ranks[u] == ranks[v]) {
        parent[v] = u;
        ranks[u]++;
    } else
        parent[u] = v;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<edge> edges(e);

    for(int i = 0; i < e; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    sort(edges.begin(), edges.end(), compare);

    for(int i = 1; i <= v; i++) {
        parent[i] = i;
        ranks[i] = 1;
    }

    int sum = 0;
    for(int i = 0; i < e; i++) {
        int a = find(edges[i].from);
        int b = find(edges[i].to);

        if(a != b) {
            merge(edges[i].from, edges[i].to);
            sum += edges[i].cost;
        }
    }

    cout << sum << endl;
}