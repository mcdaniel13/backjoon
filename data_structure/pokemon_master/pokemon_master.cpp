/*
 * https://www.acmicpc.net/problem/1620
 */

#include <iostream>
#include <map>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

const int NMAX = 100001;

int n, m;

char str[21];

string pokemonName[NMAX];
map<string, int> pokemonNum;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%s", str);
        string s = str;
        pokemonName[i] = s;
        pokemonNum[s] = i;
    }

    for(int i = 0; i < m; i++) {
        scanf("%s", str);
        string s = str;
        if(isdigit(str[0]))
            printf("%s\n", pokemonName[stoi(s)].c_str());
        else
            printf("%d\n", pokemonNum[s]);
    }
}