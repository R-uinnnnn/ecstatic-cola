#include <iostream>
#include <conio.h> // 用于 _getch()

using namespace std;

const int ROWS = 5;
const int COLS = 5;

char level[ROWS][COLS] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', 'B', ' ', '#'},
    {'#', ' ', ' ', 'A', '#'},
    {'#', '#', '#', '#', '#'}
};

int playerPos[2];
int boxPos[2];

void PrintLevel() {
    system("cls"); // 清空控制台

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << level[i][j] << ' ';
        }
        cout << endl;
    }
}

bool IsGameOver() {
    return level[boxPos[0]][boxPos[1]] == 'A';
}

void MovePlayer(int dx, int dy) {
    int newPlayerX = playerPos[0] + dx;
    int newPlayerY = playerPos[1] + dy;

    if (level[newPlayerX][newPlayerY] != '#') {
        level[playerPos[0]][playerPos[1]] = ' ';
        playerPos[0] = newPlayerX;
        playerPos[1] = newPlayerY;
        level[playerPos[0]][playerPos[1]] = 'A';
    }
}

void MoveBox(int dx, int dy) {
    int newBoxX = boxPos[0] + dx;
    int newBoxY = boxPos[1] + dy;

    if (level[newBoxX][newBoxY] == ' ' || level[newBoxX][newBoxY] == 'B') {
        level[boxPos[0]][boxPos[1]] = ' ';
        boxPos[0] = newBoxX;
        boxPos[1] = newBoxY;
        level[boxPos[0]][boxPos[1]] = 'B';
    }
}

int main() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (level[i][j] == 'A') {
                playerPos[0] = i;
                playerPos[1] = j;
            }
            else if (level[i][j] == 'B') {
                boxPos[0] = i;
                boxPos[1] = j;
            }
        }
    }

    while (!IsGameOver()) {
        PrintLevel();

        char move = _getch();

        switch (move) {
            case 'w':
                MovePlayer(-1, 0);
                break;
            case 's':
                MovePlayer(1, 0);
                break;
            case 'a':
                MovePlayer(0, -1);
                break;
            case 'd':
                MovePlayer(0, 1);
                break;
        }

        // 在实际游戏中，可能需要处理箱子的移动
        // 这里只是简单示例，未完整实现箱子的移动逻辑
    }

    cout << "游戏结束！" << endl;

    return 0;
}
