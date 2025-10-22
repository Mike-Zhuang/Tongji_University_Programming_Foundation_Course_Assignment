#include <iostream>
using namespace std;
int main() {
    int num[20] = {};
    cout << "请输入20个整数：" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - 1 - i; j++) {
            if (num[j] > num [j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << num[i] << " ";
    }
    return 0;
}