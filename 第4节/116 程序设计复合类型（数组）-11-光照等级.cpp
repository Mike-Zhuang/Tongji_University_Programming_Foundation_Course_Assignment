#include <iostream>
using namespace std;

int main() {
    int source[9][9] = {0};
    int level[9][9] = {0};


    int la[81], lb[81], lc[81];//存储光源的位置和亮度
    int cnt = 0;

    int a, b, c;
    while (cin >> a) {
        if (a == -1) break;
        cin >> b >> c;
        source[a][b] = c;
        la[cnt] = a; lb[cnt] = b; lc[cnt] = c;
        ++cnt;
    }

    // 计算每个格子的光照等级
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int best = 0;
            for (int k = 0; k < cnt; ++k) {
                int manhattan_distance = abs(i - la[k]) + abs(j - lb[k]);
                int v = lc[k] - manhattan_distance;
                if (v > best) {
                    best = v;
                }
            }
            level[i][j] = best;
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (source[i][j] > 0) {
                cout << '*' << ' ';
            } else {
                cout << level[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}