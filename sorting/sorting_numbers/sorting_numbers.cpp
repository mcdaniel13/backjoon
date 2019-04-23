/*
 * https://www.acmicpc.net/problem/10989
 */

#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int arr[10001];
    for(int i = 1; i <= 10000; i++)
        arr[i] = 0;

    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
    }

    for(int i = 1; i <= 10000; i++)
        for(int j = 0; j < arr[i]; j++)
            printf("%d\n", i);

    return 0;
}

