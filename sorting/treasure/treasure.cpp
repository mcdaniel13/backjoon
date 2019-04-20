/*
 * https://www.acmicpc.net/problem/1026
 */
#include<stdio.h>

using namespace std;

int n;

int a[50];
int b[50];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    //insertionSort
    //현재 소팅을 시작해야되는 블록
    for(int i = 1; i < n; i++) {
        int key = a[i];
        // 소팅이 완료된 블록
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(a[j] > key)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = key;
    }

    for(int i = 1; i < n; i++) {
        int key = b[i];
        // 소팅이 완료된 블록
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(b[j] < key)
                b[j + 1] = b[j];
            else
                break;
        }
        b[j + 1] = key;
    }


    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    printf("%d", sum);
}