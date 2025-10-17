#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << "请输入N+1行整数，第一行仅一个整数 N，";
    cout << "代表后续输入的行数。后续N行每行有两个数，依次是学分和五分制绩点。"<<endl;
    int N;
    cin >> N;
    double credits;
    int points;
    double avg = 0.0;
    double total_credits = 0.0;
    double sum = 0.0;
    cout << setiosflags(ios::fixed) << setprecision(2);
    for (int i = 0; i < N; ++i) {
        cin >> credits >> points;
        total_credits += credits;
        sum += credits * points;
        avg = sum/total_credits;
        cout << "当前均绩为" << avg << "。" << endl;
    }
}