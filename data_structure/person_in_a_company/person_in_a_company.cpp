/*
 * https://www.acmicpc.net/problem/7785
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    map<string, int> person;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string name, pos;
        cin >> name >> pos;
        if(pos == "enter") {
            person.insert(make_pair(name, 1));
        } else {
            person.erase(name);
        }
    }

    auto it = person.end();
    it--;
    for(it; it != person.begin(); it--) {
        printf("%s\n", it->first.c_str());
    }
    printf("%s\n", it->first.c_str());
}