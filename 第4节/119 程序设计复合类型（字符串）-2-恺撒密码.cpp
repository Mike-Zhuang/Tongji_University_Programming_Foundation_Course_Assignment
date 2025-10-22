#include <iostream>
using namespace std;
int main() {
    cout << "请输入待转换的密码：" << endl;
    char password[200];
    cin.getline(password, 200);
    cout << "请输入偏移量，负数代表向前偏移，正数代表向后偏移: " << endl;
    int offset;
    cin >> offset;
    for (int i = 0; password[i] != '\0'; i++) {
        char ch = password[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + offset + 26) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + offset + 26) % 26 + 'A';
        }
        password[i] = ch;
    }
    cout << password << endl;
    return 0;
}