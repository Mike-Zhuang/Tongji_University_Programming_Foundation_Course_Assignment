#include <iostream>
#include <iomanip>
using namespace std;
double jiecheng(int n) {
    int i;
    int result = 1;
    for (i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}
int main() {
    cout << "请输入级数项数：";
    int n;
    cin >> n;
    double e = 0.0;
    double every = 0.0;
    for (int i = 1; i <= n + 1 ; i++) {
        every = 1.0 / jiecheng(i - 1);
        e = e + every;
    }
    cout << "估算值为：" << fixed << setprecision(10) << e << "。" << endl;
    return 0;
}
