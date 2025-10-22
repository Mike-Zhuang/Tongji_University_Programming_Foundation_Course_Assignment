#include <iostream>
using namespace std;
int main() {
    cout << "请输入你的车辆编号和停车位的编号" << endl;
    cout << "如果你的车辆已经停靠这个停车位上，我告诉你在哪个车位。" << endl;
    cout << "如果该编号车位已经有其他车，告知是哪一辆车。" << endl;
    cout << "如果该车位没有车，告诉你可以停在这个车位上。" << endl;
    int car_num, park_num;
    int parking[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    while (cin >> car_num) {
        if (car_num == -1) {
            break;
        }
        cin >> park_num;


        int state = -1;
        for (int i = 0; i < 10; ++i) {
            if (parking[i] == car_num) {
                state = i;
                break;
            }
        }
        if (state != -1 && state != park_num) {
            cout << "该车已经停在" << state << "号车位了！" << endl;
            continue;
        }

        if (parking[park_num] == car_num) {
            cout << "该车已经停在" << park_num << "号车位了！" << endl;
        }
        else if (parking[park_num] != -1) {
            cout << parking[park_num] << "号车已经占据该车位了！" << endl;
        }
        else {
            parking[park_num] = car_num;
            cout << car_num << "号车成功停靠在" << park_num << "号车位！" << endl;
        }
    }
}