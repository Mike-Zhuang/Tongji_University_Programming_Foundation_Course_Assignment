#include <iostream>
using namespace std;
int main() {
    cout<<"请输入三个正整数，以十进制、八进制、十六进制的顺序输入：";
    int num_10,num_8,num_16;
    cin>>dec>>num_10>>oct>>num_8>>hex>>num_16;
    cout<<dec<<num_10<<" "<<oct<<num_10<<" "<<hex<<num_10<<endl;
    cout<<dec<<num_8<<" "<<oct<<num_8<<" "<<hex<<num_8<<endl;
    cout<<dec<<num_16<<" "<<oct<<num_16<<" "<<hex<<num_16<<endl;
    return 0;
}