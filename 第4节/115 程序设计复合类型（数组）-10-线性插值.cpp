#include <iostream>
using namespace std;
int main() {
    cout << "请输入一个3*3的矩阵，我会对其扩大成5*5的矩阵：" << endl;
    int matrixOrigional[3][3] = {0};
    int matrixNew[5][5] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrixOrigional[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrixNew[i*2][j*2] = matrixOrigional[i][j];
        }
    }

    for (int i = 1; i < 5; i += 2) {
        for (int j = 1; j < 5; j += 2) {
            matrixNew[i][j] = (matrixNew[i-1][j-1] + matrixNew[i+1][j-1] + matrixNew[i-1][j+1] + matrixNew[i+1][j+1]) / 4;
        }
    }

    for (int i = 0; i < 5; i += 2) {
        for (int j = 1; j < 5; j += 2) {
            matrixNew[i][j] = (matrixNew[i][j-1] + matrixNew[i][j+1]) / 2;
        }
    }

    for (int i = 1; i < 5; i += 2) {
        for (int j = 0; j < 5; j += 2) {
            matrixNew[i][j] = (matrixNew[i-1][j] + matrixNew[i+1][j]) / 2;
        }
    }

    cout << "进行简单插值后的结果为：" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrixNew[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}