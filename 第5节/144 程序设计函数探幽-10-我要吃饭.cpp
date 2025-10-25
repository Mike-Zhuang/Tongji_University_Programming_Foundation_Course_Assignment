#include <iostream>
using namespace std;

static const int search_x[4] = {0, 1, 0, -1};
static const int search_y[4] = {1, 0, -1, 0};
int matrix[9][9] = {0};

inline bool inside(int x, int y) {//判断坐标是否在范围内
    return x >= 0 && x <= 8 && y >= 0 && y <= 8;
}

bool find_path(int x, int y) {
    if (!inside(x, y) || matrix[x][y] == 0) {
        return false;
    }

    if (x == 0 || x == 8 || y == 0 || y == 8) {
        matrix[x][y] = 2; //2为路径
        return true;
    }

    matrix[x][y] = 0;

    for (int k = 0; k < 4; ++k) {
        int x_possiblenext = x + search_x[k];
        int y_possiblenext = y + search_y[k];
        if (find_path(x_possiblenext, y_possiblenext)) {
            matrix[x][y] = 2;
            return true;
        }
    }
    return false;
}

void print_path(int x, int y) {
    cout << x << "," << y << endl;
    if (x == 0 || x == 8 || y == 0 || y == 8) {
        return;
    }
    matrix[x][y] = -1;
    for (int k = 0; k < 4; ++k) {
        int x_possiblenext = x + search_x[k];
        int y_possiblenext = y + search_y[k];
        if (inside(x_possiblenext, y_possiblenext) && matrix[x_possiblenext][y_possiblenext] == 2) {
            print_path(x_possiblenext, y_possiblenext);
            return;
        }
    }
}

int eat (int x, int y) {
    find_path(x, y);
    print_path(x, y);
    return 0;
}

int main() {
    int x, y;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> matrix[i][j];
        }
    }
    cin >> x >> y;

    eat(x, y);
    return 0;
}