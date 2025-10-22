#include <iostream>
using namespace std;
int main() {
    int matrix[4][4] = {};
    int sum_hang = 0, sum_lie = 0;
    cout << "请输入一个4*4的矩阵：" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "每一行元素的和：";
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            sum_hang += matrix[i][j];
        }
        cout << sum_hang << " ";
        sum_hang = 0;
    }
    cout << "\n每一列元素的和：";
    for (int j = 0; j <= 3; j++) {
        for (int i = 0; i <= 3; i++) {
            sum_lie += matrix[i][j];
        }
        cout << sum_lie << " ";
        sum_lie = 0;
    }
    return 0;
}