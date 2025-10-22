#include <iostream>
using namespace std;
int main() {
    cout << "一共有100盏个彩灯，编号0~99\n"
            "我会接收若干遥控器操作输入，输出每种状态对应的灯的序号。\n"
            "若输入为 1，则所有质数灯改变自身的开关状态。\n"
            "若输入为 2，则所有合数灯改变自身的开关状态。\n"
            "若输入为 3，则所有奇数灯改变自身的开关状态。\n"
            "若输入为 4，则所有偶数灯改变自身的开关状态。" << endl;
    int state[100] = {0};
    bool is_prime[100] = {false};
    bool is_composite[100] = {false};
    for (int i = 0; i < 100; ++i) {
        bool prime = true;
        if (i < 2) {
            prime = false;
        }
        else {
            for (int a = 2; a * a <= i; ++a) {
                if (i % a == 0) {
                    prime = false;
                    break;
                }
            }
        }
        is_prime[i] = prime;
        is_composite[i] = (i >= 2 && !prime);
    }

    int input;
    while (cin >> input) {
        if (input == -1) {
            break;
        }
        if (input == 1) {
            for (int i = 0; i < 100; ++i)
                if (is_prime[i]) {
                    state[i] = (state[i] + 1) % 3;
                }
        }
        else if (input == 2) {
            for (int i = 0; i < 100; ++i)
                if (is_composite[i]) {
                    state[i] = (state[i] + 1) % 3;
                }
        }
        else if (input == 3) {
            for (int i = 0; i < 100; ++i)
                if (i % 2 == 1) {
                    state[i] = (state[i] + 1) % 3;
                }
        }
        else if (input == 4) {
            for (int i = 0; i < 100; ++i)
                if (i % 2 == 0) {
                    state[i] = (state[i] + 1) % 3;
                }
        }
    }

    cout << "熄灭：";
    for (int i = 0; i < 100; ++i) {
        if (state[i] == 0) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    cout << "长亮：";
    for (int i = 0; i < 100; ++i) {
        if (state[i] == 1) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    cout << "闪烁：";
    for (int i = 0; i < 100; ++i) {
        if (state[i] == 2) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}