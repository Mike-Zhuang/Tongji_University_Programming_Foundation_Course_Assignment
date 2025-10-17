#include <iostream>
using namespace std;
int main() {
    int height_cm, weight_kg;
    cout << "请输入身高（厘米）和体重（千克），用空格分隔：";
    cin >> height_cm >> weight_kg;
    double height_m = height_cm / 100.0;
    double bmi = weight_kg / (height_m * height_m);
    bmi += 1e-10;
    cout << "此人BMI为" << bmi << "。" << endl;
    return 0;
}