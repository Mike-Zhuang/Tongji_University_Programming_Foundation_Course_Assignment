#include <iostream>
using namespace std;
int main() {
    int shuzu[10];
    int i;
    cout << "请输入10个整数：" << endl;
    for (i = 0; i < 10; i++) {
        cin >> shuzu[i];
    }
    cout << "逆序输出结果为：" << endl;
    for (i = 9; i >= 0; i--) {
        cout << shuzu[i] << " ";
    }
}