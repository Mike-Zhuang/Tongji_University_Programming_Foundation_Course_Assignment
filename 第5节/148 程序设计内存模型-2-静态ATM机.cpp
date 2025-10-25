#include <iostream>
using namespace std;

void atm(int money)
{
    /****************** TODO ******************/

    static long long balance = 100;
    balance = balance + money;
    if (balance >= 0) {
        if (money >= 0) {
            cout << "存钱成功\n";
            cout << "当前余额为" << balance << "元。" << endl;
        }
        else {
            cout << "取钱成功\n";
            cout << "当前余额为" << balance << "元。" << endl;
        }
    }
    else {
        cout << "余额不足\n";
        balance = balance - money;
        cout << "当前余额为" << balance << "元。" << endl;
    }


    /**************** TODO-END ****************/
}

int main()
{
    int query;

    cin >> query;
    while (query != 0)
    {
        atm(query);
        cin >> query;
    }

    return 0;
}