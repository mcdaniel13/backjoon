/*
 * https://www.acmicpc.net/problem/16235
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct trees {
    int x;
    int y;
    int age;

    trees() {
        x = 0;
        y = 0;
        age = 0;
    }
};

const int NMAX = 11;

int N, M, K;

int map[NMAX][NMAX];
int add[NMAX][NMAX];
int moving[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool compare(trees first, trees second) {
    return first.age < second.age;
}

void print(const vector<trees> &tree, const vector<trees> &dead) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "== alive ==" << endl;
    for(int i = 0; i < tree.size(); i++) {
        cout << tree[i].x << tree[i].y << tree[i].age << endl;
    }

    cout << "== dead ==" << endl;
    for(int i = 0; i < dead.size(); i++) {
        cout << dead[i].x << dead[i].y << dead[i].age << endl;
    }

}

int solve(vector<trees> &tree) {
    for(int i = 0; i < K; i++) {
//        cout << "==== # " << i + 1 << " years ====" << endl;
        vector<trees> dead;
        vector<trees> alive;
        //Spring
        sort(tree.begin(), tree.end(), compare);
        for(int j = 0; j < tree.size(); j++) {
            if(map[tree[j].x][tree[j].y] >= tree[j].age) {
                map[tree[j].x][tree[j].y] -= tree[j].age;
                tree[j].age++;
                alive.push_back(tree[j]);
            } else {
                dead.push_back(tree[j]);
            }
        }
//        cout << "==== Spring ==== curM = " << alive.size() << endl;
//        print(alive, dead);

        //Summer
        for(int j = 0; j < dead.size(); j++) {
            map[dead[j].x][dead[j].y] += dead[j].age / 2;
        }
//        cout << "==== Summer ==== curM = " << alive.size() << endl;
//        print(alive, dead);

        //Fall
        for(int j = 0; j < alive.size(); j++) {
            if(alive[j].age % 5 == 0) {
                for(int k = 0; k < 8; k++) {
                    int curX = alive[j].x + moving[k][0];
                    int curY = alive[j].y + moving[k][1];
                    if(curX >= 1 && curX <= N && curY >= 1 && curY <= N) {
                        trees newTree;
                        newTree.x = curX;
                        newTree.y = curY;
                        newTree.age = 1;
                        alive.push_back(newTree);
                    }
                }
            }
        }
//        cout << "==== Fall ==== curM = " << alive.size() << endl;
//        print(alive, dead);

        //Winter
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                map[j][k] += add[j][k];
            }
        }
//        cout << "==== Winter ==== curM = " << alive.size() << endl;
//        print(alive ,dead);

        //init
        tree.clear();
        for (int j = 0; j < alive.size(); j++) {
            tree.push_back(alive[j]);
        }
//        print(tree, alive);
    }

    return tree.size();
}

int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> add[i][j];
            map[i][j] = 5;
        }
    }

    vector<trees> tree(M);
    for(int i = 0; i < M; i++) {
        cin >> tree[i].x >> tree[i].y >> tree[i].age;
    }

//    cout << "==== init ====" << endl;
//    print(tree);

    cout << solve(tree) << endl;
}