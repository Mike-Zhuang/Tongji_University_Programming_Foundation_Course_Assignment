#include <iostream>
using namespace std;

double convert(double c);
int main() {
    double celsius, fahrenheit;
    cout<<"请输入摄氏度";
    cin>>celsius;
    fahrenheit = convert(celsius);
    cout<<"摄氏温度"<<celsius<<"度对应华氏温度"<<fahrenheit<<"度。"<<endl;
}
double convert(double c) {
    float temp = c*1.8+32;
    return temp;
}