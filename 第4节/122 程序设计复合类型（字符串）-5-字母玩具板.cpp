#include <iostream>
using namespace std;

int main() {
    char matrix[5][5];
    char direction;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> matrix[i][j];
    cin >> direction;

    char output[5][5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            output[i][j] = '*';

    if (direction == 'A') {
        for (int i = 0; i < 5; ++i) {
            int k = 0;
            for (int j = 0; j < 5; ++j)
                if (matrix[i][j] != '*') {
                    output[i][k++] = matrix[i][j];
                }
        }
    }
    else if (direction == 'D') {
        for (int i = 0; i < 5; ++i) {
            int k = 4;
            for (int j = 4; j >= 0; --j)
                if (matrix[i][j] != '*') {
                    output[i][k--] = matrix[i][j];
                }
        }
    }
    else if (direction == 'W') {
        for (int j = 0; j < 5; ++j) {
            int k = 0;
            for (int i = 0; i < 5; ++i)
                if (matrix[i][j] != '*') {
                    output[k++][j] = matrix[i][j];
                }
        }
    }
    else if (direction == 'S') {
        for (int j = 0; j < 5; ++j) {
            int k = 4;
            for (int i = 4; i >= 0; --i)
                if (matrix[i][j] != '*') {
                    output[k--][j] = matrix[i][j];
                }
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (j) cout << ' ';
            cout << output[i][j];
        }
        cout << '\n';
    }
    return 0;
}
