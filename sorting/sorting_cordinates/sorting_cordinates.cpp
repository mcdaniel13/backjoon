/*
 * https://www.acmicpc.net/problem/11650
 */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> &first, pair<int,int> &second) {
    if(first.first == second.first) {
        return first.second < second.second;
    } else
        return first.first < second.first;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].first, arr[i].second);
    }

    return 0;
}