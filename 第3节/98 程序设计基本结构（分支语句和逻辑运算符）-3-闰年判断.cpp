#include <iostream>
using namespace std;
int main() {
    int year;
    if (!(cin >> year)) {
        cout << "输入错误" << endl;
        return 0;
    }
    if (((year % 4 == 0) && (year % 100 != 0) )|| (year % 400 == 0))
        cout << year << "年是闰年。" << endl;
    else
        cout << year << "年不是闰年。" << endl;
}