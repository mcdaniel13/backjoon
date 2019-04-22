/*
 * https://www.acmicpc.net/problem/1427
 */


#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void swap(vector<int> &arr, int right, int left) {
    int temp = arr[right];
    arr[right] = arr[left];
    arr[left] = temp;
}

int partition(vector<int> &arr, int left, int right, int pivotIndex) {
    int pivot = arr[pivotIndex];
    while(left <= right) {
        while(arr[left] <= pivot && left <= right)
            left++;
        while(arr[right] > pivot && left <= right)
            right--;
        if(left < right)
            swap(arr, left, right);
    }
    swap(arr, right, pivotIndex);

    return right;
}

void quickSort(vector<int> &arr, int left, int right) {
    if(left < right) {
        int pivot = partition(arr, left + 1, right, left);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }

}

int main() {
    string temp;

    cin >> temp;

    vector<int> arr(temp.length());
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = temp[i] - '0';
    }

    quickSort(arr, 0, arr.size() - 1);

    for(int i = arr.size() - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");
}