#include <iostream>
using namespace std;

/****************** TODO ******************/

int integer(double a) {
    int integer = (int)a;
    return integer;
}

double decimal(double a) {
    double decimal = a - integer(a);
    return decimal;
}


/**************** TODO-END ****************/

int main()
{
    double num = 0;

    cin >> num;
    cout << "整数部分是" << integer(num)
         << "，小数部分是" << decimal(num) << "。" << endl;

    return 0;
}