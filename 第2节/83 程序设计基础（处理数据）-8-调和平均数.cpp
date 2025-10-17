#include <iostream>
using namespace std;
int main() {
    int n_1, n_2;
    double n_harmonic;
    cout << "请输入两个正整数：";
    cin >> n_1 >> n_2;
    n_harmonic = 2.0 * n_1 * n_2 / (n_1 + n_2);
    cout << n_harmonic << endl;
    return 0;
}