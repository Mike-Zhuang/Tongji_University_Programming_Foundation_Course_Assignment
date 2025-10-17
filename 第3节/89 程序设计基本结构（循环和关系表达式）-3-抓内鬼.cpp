#include <iostream>
using namespace std;
int main(){
    cout << "请输入几个你想要输入的东西，每个输入之间用空格或换行符隔开。\n"
            "你输入的每个输入都可能是整数或非数字字符。整数均在 int 类型可表示的范围内。\n"
            "我的程序将会输出首个非数字的输入的位置。位置从0开始编号。";
    int num=0;
    int order;
    while (cin >> order)
    {
        num++;
    }
    cout << num << endl;
}

