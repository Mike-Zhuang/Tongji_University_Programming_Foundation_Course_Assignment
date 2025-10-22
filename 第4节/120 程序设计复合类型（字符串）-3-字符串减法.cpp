#include <iostream>
using namespace std;

int main() {
    char str1[201], str2[201];
    cout << "请输入第一个字符串：" << endl;
    cin.getline(str1, 201);
    cout << "请输入第二个字符串：" << endl;
    cin.getline(str2, 201);

    bool remove[128] = {false};//ASCII码的范围是0~127
    for (int i = 0; str2[i] != '\0'; ++i) {
        remove[(unsigned char)str2[i]] = true;
    }

    bool empty = true;
    for (int i = 0; str1[i] != '\0'; ++i) {
        if (!remove[(unsigned char)str1[i]]) {
            cout << str1[i];
            empty = false;
        }
    }
    if (empty) {
        cout << "空串";
    }
    cout << endl;
    return 0;
}
