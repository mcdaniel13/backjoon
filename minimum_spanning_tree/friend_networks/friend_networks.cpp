/*
 * https://www.acmicpc.net/problem/4195
 */

#include <cstdio>
#include <map>
#include <string>

using namespace std;
int t, n;

int parent[100001];
int ranks[100001];
char to[21];
char from[21];

int find(int u) {
    if(u == parent[u])
        return u;
    else
        return parent[u] = find(parent[u]);
}

int merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        parent[v] = u;
        ranks[u] += ranks[v];
        ranks[v] = 1;
    }
    return ranks[u];
}

int main() {
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        int cnt = 0;
        map<string, int> name;
        for(int j = 0; j < n; j++) {
            scanf("%s %s", &to, &from);
            if(name.find(to) == name.end()) {
                name.insert(make_pair(to, cnt));
                parent[cnt] = cnt;
                ranks[cnt] = 1;
                cnt++;
            }
            if(name.find(from) == name.end()) {
                name.insert(make_pair(from, cnt));
                parent[cnt] = cnt;
                ranks[cnt] = 1;
                cnt++;
            }
            printf("%d\n", merge(name[to], name[from]));
        }
    }
}