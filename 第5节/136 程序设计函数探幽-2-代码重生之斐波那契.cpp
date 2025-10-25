#include <iostream>
using namespace std;

/****************** TODO ******************/

size_t fibonacci(long long int n)
{
    long long int a = 1, b = 1, c = 0;
    for (long long int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return c;
    }
}

/**************** TODO-END ****************/

int main()
{
    int num = 0; // 斐波那契数列的项数

    cin >> num;
    cout << "斐波那契数列中第" << num
         << "项的值为" << fibonacci(num) << "。" << endl;

    return 0;
}