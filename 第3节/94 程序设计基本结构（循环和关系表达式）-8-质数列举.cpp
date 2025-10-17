#include <iostream>
using namespace std;
int main() {
    cout << "请你输入两个正整数，代表区间端点 a 和 b (1 ≤ a ≤ b ≤ 100000)，\n我会输出他们之间的质数\n";
    long long a, b, i, j;
    cin >> a >> b;
    cout << "区间中的质数有：\n";
    for (i = a; i <= b ; i ++) {
        for (j = 2; pow(j, 2) <= i; j ++) {
            if (i % j == 0) {
                break;
            }
        }
        if (pow(j, 2) > i) {
            cout << i << " ";
        }
    }
}