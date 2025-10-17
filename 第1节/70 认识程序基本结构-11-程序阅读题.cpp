#include <iostream>
#include <limits>
using namespace std;

int main() {
    int num;

    // 测试输入 0
    cout << "请输入 0: ";
    cin >> num;
    cout << "cin.good(): " << cin.good() << endl;
    cout << "cin.fail(): " << cin.fail() << endl;
    cout << "读取的值: " << num << endl;

    // 清除错误状态和缓冲区
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    // 测试输入 Surprise!
    cout << "请输入 Surprise!: ";
    cin >> num;
    cout << "cin.good(): " << cin.good() << endl;
    cout << "cin.fail(): " << cin.fail() << endl;
    cout << "读取的值: " << num << endl;

    // 清除错误状态和缓冲区
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    // 测试输入 9999999999 (超过 int 范围)
    cout << "请输入 9999999999: ";
    cin >> num;
    cout << "cin.good(): " << cin.good() << endl;
    cout << "cin.fail(): " << cin.fail() << endl;
    cout << "读取的值: " << num << endl;

    return 0;
}