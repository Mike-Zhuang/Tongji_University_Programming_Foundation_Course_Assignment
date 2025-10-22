#include <iostream>
#include <string>
using namespace std;
int main() {
    string line;
    while (getline(cin, line)) {
        int n = (int)line.size();
        int i = 0;

        int sign = 1;
        if (line[i] == '+' || line[i] == '-') {
            if (line[i] == '-') {
                sign = -1;
            } else {
                sign = 1;
            }
            i++;
        }
        if (i == n || !(line[i] >= '0' && line[i] <= '9')) {
            cout << "输入错误！" << endl;
            continue;
        }

        long long num = 0;
        while (i < n && line[i] >= '0' && line[i] <= '9') {
            num = num * 10 + (line[i] - '0');
            i++;
        }

        // 不能有多余字符，如123c
        if (i != n) {
            cout << "输入错误！" << endl;
            continue;
        }

        int result = (int)(sign == 1 ? num : -num);
        cout << result << endl;
        break;


    }
}