#include <iostream>
using namespace std;
int main() {
    cout << "请输入项数，我会输出斐波那契数列中对应项的值。";
    int n;
    cin >> n;
    long long int a = 1, b = 1, c = 0;
    if (n == 1 || n == 2) {
        cout << "第" << n << "项的值为1。" << endl;
    }
    else {
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        cout << "斐波那契数列中第" << n << "项的值为" << c << "。" << endl;
    }
    return 0;
}