#include <iostream>
using namespace std;

/****************** TODO ******************/

bool pass(char grade) {
    if (grade == 'F') {
        return 0;
    }
    else {
        return 1;
    }
}

bool pass(int score_100) {
    if (score_100 >= 60) {
        return 1;
    }
    else {
        return 0;
    }
}

bool pass(double score_5) {
    if (score_5 >= 2.00) {
        return 1;
    }
    else {
        return 0;
    }
}

/**************** TODO-END ****************/

// 下面是一个使用你所编写函数的样例程序
int main()
{
    // 三种情况分别测试
    char grade = '\0';
    int score_100 = 0;
    double score_5 = 0;

    cin >> grade >> score_100 >> score_5;

    cout << "成绩：" << grade << " 及格情况："
        << (pass(grade) ? "及格" : "不及格") << endl;

    cout << "成绩：" << score_100 << " 及格情况："
        << (pass(score_100) ? "及格" : "不及格") << endl;

    cout << "成绩：" << score_5 << " 及格情况："
        << (pass(score_5) ? "及格" : "不及格") << endl;

    return 0;
}