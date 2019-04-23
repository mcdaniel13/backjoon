/*
 * https://www.acmicpc.net/problem/1181
 */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string first, string second) {
    if(first.length() == second.length()) {
        return first < second;
    } else
        return first.length() < second.length();
}

int main() {
    int n;
    scanf("%d", &n);
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        char temp[51];
        scanf("%s", temp);
        arr[i] = (string) temp;
    }

    sort(arr.begin(), arr.end(), compare);

    printf("%s\n", arr[0].c_str());
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i -1])
            continue;
        else
            printf("%s\n", arr[i].c_str());
    }

}