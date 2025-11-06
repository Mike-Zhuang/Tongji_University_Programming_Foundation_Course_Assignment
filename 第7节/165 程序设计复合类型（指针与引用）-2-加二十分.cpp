#include <iostream>
using namespace std;

/****************** TODO ******************/

void add_score(int &tmp1)
{
    if (tmp1 >= 80)
    {
        tmp1 = 100;
    }
    else
    {
        tmp1 += 20;
    }
}

void add_score(int *tmp2)
{
    if (*tmp2 >= 80)
    {
        *tmp2 = 100;
    }
    else
    {
        *tmp2 += 20;
    }
}
/**************** TODO-END ****************/

int main()
{
    int score = 0;
    cin >> score;

    // 调用方法一
    int tmp1 = score;
    add_score(tmp1);
    cout << "方法一得到结果：" << tmp1 << endl;

    // 调用方法二
    int tmp2 = score;
    add_score(&tmp2); // 思考：这个&是什么意思？
    cout << "方法二得到结果：" << tmp2 << endl;

    return 0;
}