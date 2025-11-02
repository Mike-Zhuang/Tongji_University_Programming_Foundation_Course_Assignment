#include <iostream>
#include <iomanip>
using namespace std;

class StudentInfo {
    /****************** TODO ******************/
public:

    static const int MAX_NAME_LEN = 20;
    static const int MAX_NUMBER_LEN = 40;

    char name[MAX_NAME_LEN] = {}; // 学生姓名
    char number[MAX_NUMBER_LEN] = {}; // 专业
    int year = 0; // 入学年份
    double score = 0.0; // 平均绩点
    /**************** TODO-END ****************/

public:
    void inputStudentInfo();
    void printStudentInfo();
};

/****************** TODO ******************/

void StudentInfo::inputStudentInfo() {
    cout << "请输入学生信息：" << endl;
    cout << "姓名：";
    cin.getline(name, StudentInfo::MAX_NAME_LEN);
    cout << "专业：";
    cin.getline(number, StudentInfo::MAX_NUMBER_LEN);
    cout << "入学年份：";
    cin >> year;
    cout << "平均绩点：";
    cin >> score;

}

void StudentInfo::printStudentInfo(){

    cout << "姓名：" << name << endl;
    cout << "专业：" << number << endl;
    cout << "入学年份：" << year << endl;
    cout << "平均绩点：" << fixed << setprecision(2) << score << endl;

}

/**************** TODO-END ****************/

int main()
{
    StudentInfo student;
    // 输入学生信息
    student.inputStudentInfo();
    // 输出学生信息
    student.printStudentInfo();

    return 0;
}