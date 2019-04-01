/*
 * https://www.acmicpc.net/problem/5373
 * [reference] https://www.youtube.com/watch?v=8XJcnUPIu_Q
 */

#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 1000;

int n;

void print(const vector<vector<vector<char>>> &cube, int index) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube[index][i][j];
        }
        cout << endl;
    }
}

void rotateClockwise(vector<vector<char>> &face) {
    char temp = face[0][0];
    face[0][0] = face[2][0];
    face[2][0] = face[2][2];
    face[2][2] = face[0][2];
    face[0][2] = temp;

    temp = face[0][1];
    face[0][1] = face[1][0];
    face[1][0] = face[2][1];
    face[2][1] = face[1][2];
    face[1][2] = temp;
}

void rollUp(vector<vector<vector<char>>> &cube) {
    vector<vector<char>> temp = cube[0];
    cube[0] = cube[4];
    cube[4] = cube[5];
    cube[5] = cube[2];
    cube[2] = temp;

    rotateClockwise(cube[5]);
    rotateClockwise(cube[5]);

    rotateClockwise(cube[4]);
    rotateClockwise(cube[4]);

    rotateClockwise(cube[1]);

    rotateClockwise(cube[3]);
    rotateClockwise(cube[3]);
    rotateClockwise(cube[3]);
}

void rollFront(vector<vector<vector<char>>> &cube) {
    vector<vector<char>> temp = cube[1];
    cube[1] = cube[4];
    cube[4] = cube[3];
    cube[3] = cube[2];
    cube[2] = temp;

    rotateClockwise(cube[2]);
    rotateClockwise(cube[2]);
    rotateClockwise(cube[2]);

    rotateClockwise(cube[3]);
    rotateClockwise(cube[3]);
    rotateClockwise(cube[3]);

    rotateClockwise(cube[4]);
    rotateClockwise(cube[4]);
    rotateClockwise(cube[4]);

    rotateClockwise(cube[1]);
    rotateClockwise(cube[1]);
    rotateClockwise(cube[1]);

    rotateClockwise(cube[0]);
    rotateClockwise(cube[0]);
    rotateClockwise(cube[0]);

    rotateClockwise(cube[5]);
}

void rotateLeft(vector<vector<vector<char>>> &cube) {
    // 0 -> 1 -> 5 -> 3
    vector<vector<char>> temp = cube[0];
    for(int i = 0; i < 3; i++) {
        cube[0][i][0] = cube[3][i][0];
        cube[3][i][0] = cube[5][i][0];
        cube[5][i][0] = cube[1][i][0];
        cube[1][i][0] = temp[i][0];
    }
    rotateClockwise(cube[4]);
}

void rotateRight(vector<vector<vector<char>>> &cube) {
    // 0 -> 3 -> 5 -> 1
    vector<vector<char>> temp = cube[0];
    for(int i = 0; i < 3; i++) {
        cube[0][i][2] = cube[1][i][2];
        cube[1][i][2] = cube[5][i][2];
        cube[5][i][2] = cube[3][i][2];
        cube[3][i][2] = temp[i][2];
    }
    rotateClockwise(cube[2]);
}

void solve(vector<vector<vector<char>>> &cube, char face, char direction) {
    //clockwise
    int rot = 1;
    //counterclockwise
    if(direction == '-')
        rot = 3;

    if(face == 'U') {
        rollUp(cube);
        for(int i = 0; i < rot; i++)
            rotateRight(cube);
        for(int i = 0; i < 3; i++)
            rollUp(cube);
    } else if(face == 'D') {
        rollUp(cube);
        for(int i = 0; i < rot; i++)
            rotateLeft(cube);
        for(int i = 0; i < 3; i++)
            rollUp(cube);
    } else if(face == 'F') {
        rollFront(cube);
        for(int i = 0; i < rot; i++)
            rotateRight(cube);
        for(int i = 0; i < 3; i++)
            rollFront(cube);
    } else if(face == 'B') {
        rollFront(cube);
        for(int i = 0; i < rot; i++)
            rotateLeft(cube);
        for(int i = 0; i < 3; i++)
            rollFront(cube);
    } else if(face == 'L') {
        for(int i = 0; i < rot; i++)
            rotateLeft(cube);
    } else if(face == 'R') {
        for(int i = 0; i < rot; i++)
            rotateRight(cube);
    }
}

int main() {
    int t;
    cin >> t;

    for(int k = 0; k < t; k++) {
        cin >> n;
        //init cube
        vector<vector<vector<char>>> cube;
        cube.push_back(vector<vector<char>>(3, vector<char>(3, 'w')));
        cube.push_back(vector<vector<char>>(3, vector<char>(3, 'r')));
        cube.push_back(vector<vector<char>>(3, vector<char>(3, 'b')));
        cube.push_back(vector<vector<char>>(3, vector<char>(3, 'o')));
        cube.push_back(vector<vector<char>>(3, vector<char>(3, 'g')));
        cube.push_back(vector<vector<char>>(3, vector<char>(3, 'y')));

        //input
        for(int i = 0; i < n; i++) {
            char face, direction;
            cin >> face >> direction;
            //move
            solve(cube, face, direction);
        }

        print(cube, 0);
    }
}