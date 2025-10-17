#include <iostream>
using namespace std;
int main() {
    double n_total, n_decimal;
    int n_integer;
    cout << "请输入一个正数：";
    cin >> n_total;
    n_integer = (int)n_total;
    n_decimal = n_total - n_integer;
    cout << "整数部分是" << n_integer <<"，";
    cout << "小数部分是：" << n_decimal << "。" <<endl;
    return 0;
}