#include <iostream>
using namespace std;
int main() {
    cout << "请输入一个8*8矩阵，我会帮你进行2*2最大池化操作：" << endl;

    int matrix[8][8] = {0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> matrix[i][j];
        }
    }

    int pooled[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i*2][j*2] >= matrix[i*2][j*2+1] && matrix[i*2][j*2] >= matrix[i*2+1][j*2] && matrix[i*2][j*2] >= matrix[i*2+1][j*2+1])
                pooled[i][j] = matrix[i*2][j*2];
            else if (matrix[i*2][j*2+1] >= matrix[i*2][j*2] && matrix[i*2][j*2+1] >= matrix[i*2+1][j*2] && matrix[i*2][j*2+1] >= matrix[i*2+1][j*2+1])
                pooled[i][j] = matrix[i*2][j*2+1];
            else if (matrix[i*2+1][j*2] >= matrix[i*2][j*2] && matrix[i*2+1][j*2] >= matrix[i*2][j*2+1] && matrix[i*2+1][j*2] >= matrix[i*2+1][j*2+1])
                pooled[i][j] = matrix[i*2+1][j*2];
            else
                pooled[i][j] = matrix[i*2+1][j*2+1];
        }
    }

    cout << "进行2*2最大池化后的结果为：" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << pooled[i][j] << " ";
        }
        cout << endl;
    }
}