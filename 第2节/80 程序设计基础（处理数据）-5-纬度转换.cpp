#include <iostream>
using namespace std;
int main() {
    int degree, minute, second;
    cout<<"请输入三个正整数，分别表示纬度中的度、分、秒：";
    cin>>degree>>minute>>second;
    double degree_converted = degree + minute / 60.0 + second / 3600.0;
    cout<<degree<<"度"<<minute<<"分"<<second<<"秒相当于"<<degree_converted<<"度。"<<endl;
    return 0;
}