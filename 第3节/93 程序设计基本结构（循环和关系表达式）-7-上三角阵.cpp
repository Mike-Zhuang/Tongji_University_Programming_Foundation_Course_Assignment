#include <iostream>
using namespace std;
int main() {
    cout << "请给我矩阵的长宽输入，我会输出对应大小的ALPD矩阵。";
    int n;
    cin >> n;
    int num = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j < i) cout << 0;
            else cout << num++;
            if (j < n) cout << " ";
        }
        cout << "\n";
    }
}