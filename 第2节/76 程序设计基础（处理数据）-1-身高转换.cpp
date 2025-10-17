#include <iostream>
using namespace std;
int main() {
    double height_m;
    int height_cm;
    cout<<"请输入身高（厘米）：";
    cin>>height_cm;
    height_m = height_cm / 100.0;
    cout<<"转换后的身高为"<<height_m<<"米。"<<endl;
    return 0;
}