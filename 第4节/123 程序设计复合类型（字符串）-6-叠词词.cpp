#include <iostream>
using namespace std;

int isWord(char unworded) {
    if (unworded >= 'a' && unworded <= 'z') return 1;
    if (unworded >= 'A' && unworded <= 'Z') return 1;
    if (unworded >= '0' && unworded <= '9') return 1;
    if (unworded == '-' || unworded == '\'') return 1;
    return 0;
}

int main() {
    char in[2000];
    cin.getline(in, 2000);
    int inlength = 0;
    while (in[inlength] != '\0') {
        ++inlength;
    }

    char out[2000];
    int outdown = 0;

    for (int indown = 0; indown < inlength; ) {
        if (isWord(in[indown])) {
            // 第一个单词
            int rightdown = indown;
            while (rightdown < inlength && isWord(in[rightdown])) {
                ++rightdown;
            }

            int pos = rightdown;//扫描后续叠词
            int sameword = 0;//是否有叠词
            char punc[2000];// 需要并到首个单词后的标点
            int puncnum = 0;

            while (true) {
                //检查是不是一个空格+单词
                if (pos < inlength && in[pos] == ' ' && pos + 1 < inlength && isWord(in[pos + 1])) {
                    int s2 = pos + 1;
                    int e2 = s2;
                    while (e2 < inlength && isWord(in[e2])) {
                        ++e2;
                    }

                    int len1 = rightdown - indown, len2 = e2 - s2;
                    int equal = (len1 == len2);
                    for (int k = 0; k < len1 && equal; ++k) {
                        if (in[indown + k] != in[s2 + k]) {
                            equal = 0;
                        }
                    }

                    if (equal) {
                        sameword = 1;
                        pos = e2;

                        // 收集紧随叠词链末尾的连续标点
                        int puncnum0 = puncnum;
                        while (pos < inlength && in[pos] != ' ' && !isWord(in[pos])) {
                            punc[puncnum++] = in[pos];
                            ++pos;
                        }

                        if (puncnum > puncnum0) {
                            break;
                        }
                        continue;
                    }
                }
                break;//if外层while
            }

            // 输出保留的第一个单词
            for (int k = indown; k < rightdown; ++k) {
                out[outdown++] = in[k];
            }

            if (sameword) {
                // 把末尾标点并回去，并跳过重复部分
                for (int k = 0; k < puncnum; ++k) {
                    out[outdown++] = punc[k];
                }
                indown = pos;
            }
            else {
                indown = rightdown;
            }
        }
        else {
            // 非单词字符（空格/标点）原样输出
            out[outdown++] = in[indown++];
        }
    }

    out[outdown] = '\0';
    cout << out;
    return 0;
}