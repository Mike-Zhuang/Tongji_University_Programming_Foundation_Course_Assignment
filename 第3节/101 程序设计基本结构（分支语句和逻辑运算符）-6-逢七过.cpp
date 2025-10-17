#include <iostream>
using namespace std;
int main() {
    cout << "请输入闭区间的两个端点，我将判断“逢七过”的数字个数：" << endl;
    long long a, b;
    cin >> a >> b;
    int count = 0;
    for (long long i = a; i <= b; i++) {
        if ((i % 7 == 0) || ((i - 7) % 10 == 0) || ((i / 10) % 10 == 7) || ((i / 100) % 10 == 7) || ((i / 1000) % 10 == 7) || ((i / 10000) % 10 == 7) || ((i / 100000) % 10 == 7)) {
            count++;
            cout << i << " ";
            continue;
        }
    }
    cout << "\n一共有" << count << "个数字需要说“过”。" << endl;
    return 0;
}