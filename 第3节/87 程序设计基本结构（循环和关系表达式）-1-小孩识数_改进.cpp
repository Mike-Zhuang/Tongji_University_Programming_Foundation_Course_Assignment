#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "请输入N和N个整数，这个程序将会把N个整数相加。\n";
    int N;
    cin >> N;

    vector<int> calculate(N);
    for (int i = 0; i < N; ++i) {
        cin >> calculate[i];
    }

    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += calculate[i];
    }

    cout << "这" << N << "个数的求和结果为" << sum << "。" << endl;
    return 0;
}
