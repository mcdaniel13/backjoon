/*
 * https://www.acmicpc.net/problem/1922
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 1001;
const int MMAX = 100000;

struct network {
    int from;
    int to;
    int cost;
    network() {}
    network(int from_, int to_, int cost_) {
        from = from_;
        to = to_;
        cost = cost_;
    }
};

int n, m, source, dest, weight;
int parents[NMAX];
int ranks[NMAX];
vector<network> edge(MMAX);

void init() {
    for(int i = 1; i <= n; i++) {
        parents[i] = i;
        ranks[i] = 1;
    }
}

bool compare(network one, network two) {
    return one.cost < two.cost;
}

int find(int u) {
    if(parents[u] == u)
        return u;
    else
        return parents[u] = find(parents[u]);
}

void merge(int x, int y) {
    int u = find(x);
    int v = find(y);

    if(ranks[u] > ranks[v])
        parents[v] = u;
    else if (ranks[u] == ranks[v]) {
        ranks[u]++;
        parents[v] = u;
    } else
        parents[u] = parents[v];
}

int kruskal() {
    int totalWeight = 0;

    sort(edge.begin(), edge.begin() + m, compare);

    for(int i = 0; i < m; i++) {
        int u = find(edge[i].from);
        int v = find(edge[i].to);

        if(u == v)
            continue;

        totalWeight += edge[i].cost;
        merge(u, v);
    }
    return totalWeight;
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    init();

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &source, &dest, &weight);
        edge[i] = network(source, dest, weight);
    }

    printf("%d\n", kruskal());
}
