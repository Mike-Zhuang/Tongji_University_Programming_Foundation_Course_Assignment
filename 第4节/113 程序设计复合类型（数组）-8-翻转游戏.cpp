#include<iostream>
using namespace std;
int main() {
    cout << "请输入一对整数，我会把3*3矩阵相对应位置及其周边的数字进行翻转：" << endl;
    int x, y;
    int matrix[5][5] = { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, };
    while (cin >> x ) {
        if (x == -1) {
            break;
        }
        cin >> y;
        x = x + 1;
        y = y + 1;
        if (int i = x - 1) {
            matrix[i][y] = 1 - matrix[i][y];
        }
        if (int i = x + 1) {
            matrix[i][y] = 1 - matrix[i][y];
        }
        for (int i = x; ; ) {
            for (int j = y - 1; j <= y + 1; j++) {
                matrix[i][j] = 1 - matrix[i][j];
            }
            break;
        }
    }
        cout << "最终的翻转结果是：" << endl;
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
}