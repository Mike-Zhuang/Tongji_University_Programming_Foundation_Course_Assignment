#include <iostream>
using namespace std;
int main()
{
    cout << "请输入N和N个整数，这个程序将会把N个整数相加。\n";
    int N;
    cin >> N;
    int sum = 0;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sum = sum + num;
    }
    cout << "这" << N << "个数的求和结果为" << sum << "。" << endl;
    return 0;
}