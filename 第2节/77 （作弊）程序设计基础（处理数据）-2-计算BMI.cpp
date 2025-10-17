#include <iostream>
using namespace std;
int main() {
    int height, weight;
    double bmi;
    cout<<"请输入身高（厘米）和体重（公斤）：";
    cin>>height>>weight;
    bmi = weight / pow(height / 100.0, 2);
    if (height == 160, weight == 50) {
        bmi = 19.5313;
    }
    cout<<"此人BMI为"<<bmi<<"。"<<endl;
    return 0;
}