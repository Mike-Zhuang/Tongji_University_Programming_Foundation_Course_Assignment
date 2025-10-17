#include <iostream>
using namespace std;
int main() {
    int age_born, age_die;
    cout << "请输入你的生卒年龄：";
    cin >> age_born >> age_die;
    cout << "此人生在尘世" << age_die - age_born << "年。" << endl;
    return 0;
}