#include <iostream>
using namespace std;
int convert(int this_year, int born_year) {
    int days = (this_year - born_year)*365;
    return days;
}
int main() {
    int this_year = 0, born_year = 0;
    cout << "请输入你的出生年份和当前年份：";
    cin >> born_year >> this_year;
    cout << "一共" << convert(this_year, born_year) << "天。" << endl;
    return 0;
}