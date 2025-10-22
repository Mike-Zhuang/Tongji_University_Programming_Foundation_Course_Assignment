#include <iostream>
#include <string>
using namespace std;
int main() {
    string num_1, num_2;
    cout << "请输入第一个大数: ";
    cin >> num_1;
    cout << "请输入第二个大数: ";
    cin >> num_2;
    string result;
    int forward = 0;
    int i = (int)num_1.length() - 1;
    int j = (int)num_2.length() - 1;
    while (i >= 0 || j >= 0 || forward) {
        int digit_1, digit_2;
        if (i >= 0) {
            digit_1 = num_1[i] - '0';//转换成数字
            i--;
        }
        else {
            digit_1 = 0;
        }
        if (j >= 0) {
            digit_2 = num_2[j] - '0';//转换成数字
            j--;
        }
        else {
            digit_2 = 0;
        }
        int sum = digit_1 + digit_2 + forward;
        forward = sum / 10;
        result = to_string(sum % 10) + result;
    }
    cout << "大数相加结果为: " << result << endl;
    return 0;
}