#include <iostream>
using namespace std;
int main() {
    int shuzu[10];
    int i;
    cout << "请输入10个整数：" << endl;
    for (i = 0; i < 10; i++) {
        cin >> shuzu[i];
    }
    cout << "请输入你想要查找的数字：" << endl;
    int want;
    while (cin >> want) {
        if (want == -1) {
            break;
        }
        bool found = false;
        for (i = 0; i < 10; i++) {
            if (shuzu[i] == want) {
                cout << want << "在数组中。" << endl;
                found = true;
                break;
            }
            if (i == 9 && !found) {
                cout << want << "不在数组中。" << endl;
            }
        }
    }
}