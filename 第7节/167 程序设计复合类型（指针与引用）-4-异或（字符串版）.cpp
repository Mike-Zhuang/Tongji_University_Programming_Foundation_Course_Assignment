#include <iostream>
#include <string.h>
using namespace std;

/****************** TODO ******************/

string &xor_str(string &dst, const string &src) {
    int length_dst = (int)dst.length();
    int length_src = (int)src.length();
    string temp_src = src;
    if (length_dst < length_src) {
        dst = string(length_src - length_dst, '0') + dst;
        length_dst = length_src;
    }
    else if (length_dst > length_src) {
        temp_src = string(length_dst - length_src, '0') + temp_src;
        length_src = length_dst;
    }
    for (int i = 0; i < length_dst; i++) {
        if (dst[i] == temp_src[i]) {
            dst[i] = '0';
        }
        else {
            dst[i] = '1';
        }
    }
    return dst;

}

/**************** TODO-END ****************/

int main()
{
    string dst, src;
    cin >> dst >> src;

    xor_str(dst, src); // dst = dst ⊕ src
    cout << dst << endl;

    // 链式异或操作
    xor_str(xor_str(dst, src), src); // dst = dst ⊕ src ⊕ src
    cout << dst << endl;
    // 链式异或操作
    xor_str(dst, src) += src; // dst = dst ⊕ src + src
    cout << dst << endl;

    cout << src << endl;

    return 0;
}