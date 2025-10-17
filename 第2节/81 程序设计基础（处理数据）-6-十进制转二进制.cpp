#include <iostream>
using namespace std;
int main() {
    int n_dec;
    cout << "请输入一个十进制数（0-255）: ";
    cin >> n_dec;
    cout << "转换后的二进制表示为: ";
    int power = 128;
    for (int i = 0; i < 8; i++) {
        int bit = n_dec / power;
        cout << bit;
        n_dec -= bit * power;
        power = power / 2;
    }
    return 0;
}