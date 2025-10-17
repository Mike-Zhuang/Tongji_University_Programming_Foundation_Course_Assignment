#include <iostream>
using namespace std;
int main() {
    cout<<"请输入一个整数，代表年数：";
    int year;
    cin>>year;
    long long seconds = year * 365LL * 24 * 60 * 60;
    cout<<year<<"年一共"<<seconds<<"秒。"<<endl;
    return 0;
}