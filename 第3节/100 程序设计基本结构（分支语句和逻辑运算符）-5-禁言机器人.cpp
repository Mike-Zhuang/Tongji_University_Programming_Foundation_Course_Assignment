#include <iostream>
using namespace std;
int main(){
    cout << "请输入两个整数 a, b，分别代表发言的小时数和分钟数：";
    int a, b;
    cin >> a >> b;
    if (((a == 15 && b >= 30) || (a == 16 && b < 15))
        || ((a == 16 && b >= 20) || (a == 17 && b < 5))) {
           if (a == 17) {
               cout << "该用户禁言时间为" << 5 - b << "分钟。";
           }
           else {
               cout << "该用户禁言时间为" << (17 * 60 + 5) - (a * 60 + b) << "分钟。";
           }
       }
    else {
        cout << "该用户禁言时间为0分钟。";
    }
}