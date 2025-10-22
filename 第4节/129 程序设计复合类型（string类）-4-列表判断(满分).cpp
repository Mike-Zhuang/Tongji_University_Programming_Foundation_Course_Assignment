#include <iostream>
#include <string>
using namespace std;

/*
 * 代码详细解释：
 *
 * 这段C++代码的功能是验证输入的字符串是否为合法的列表格式。
 * 合法格式要求：
 * 1. 以'['开头，']'结尾
 * 2. 支持嵌套列表
 * 3. 列表元素可以是整数（包括负数）或子列表
 * 4. 元素之间用逗号分隔
 * 5. 不能出现数字 空格 数字的非法情况
 *
 * 算法步骤：
 * 1. 预处理：去除所有空格，同时检查是否出现"数字 空格 数字"的情况
 * 2. 使用状态机解析：用字符串模拟栈，保存解析状态
 *    - '0': 期望元素或']'
 *    - '1': 元素后期望','或']'
 *    - '2': 逗号后期望元素
 * 3. 遍历处理后的字符串，根据当前状态和字符进行状态转换
 * 4. 最终判断是否所有状态都正确闭合
 */

int main() {
    string input;
    getline(cin, input);

    // 1) 去空格，同时检查是否出现"数字 空格 数字"的非法情况
    string s;
    bool invalid = false; // 标记是否非法
    bool prevNonSpaceIsDigit = false; // 记录前一个非空格字符是否为数字

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];

        if (c == ' ') { // 遇到空格
            size_t k = i + 1;
            // 跳过连续空格
            while (k < input.size() && input[k] == ' ') k++;

            bool nextNonSpaceIsDigit = false;
            if (k < input.size()) {
                char nc = input[k];
                if (nc >= '0' && nc <= '9') {
                    nextNonSpaceIsDigit = true;
                }
            }

            // 检查是否出现"数字 空格 数字"的情况
            if (prevNonSpaceIsDigit && nextNonSpaceIsDigit) {
                invalid = true;
                break;
            }
            continue; // 丢弃空格
        }
        else {
            s += c; // 添加非空格字符到字符串s
            prevNonSpaceIsDigit = (c >= '0' && c <= '9'); // 更新数字标记
        }
    }

    // 检查基本格式：不能为空，必须以'['开头
    if (invalid || s.empty() || s[0] != '[') {
        cout << "格式非法！" << endl;
        return 0;
    }

    // 2) 迭代解析：用字符串当栈保存状态'0','1','2'
    string st;
    st += '0'; // 最外层列表：期望元素或']'
    size_t i = 1, n = s.size(); // 从第二个字符开始解析

    while (!invalid && i < n) {
        if (st.empty()) {
            invalid = true; break;
        } // 栈为空但还有字符，非法

        int state = st[st.size() - 1] - '0'; // 获取当前状态（栈顶元素）
        char ch = s[i]; // 当前字符

        if (state == 0) { // 期望元素或']'
            if (ch == ']') {
                st.resize(st.size() - 1); // 弹出栈顶元素（闭合当前列表）
                i++; // 移动到下一个字符
                if (!st.empty()) {
                    st[st.size() - 1] = '1'; // 父列表得到一个元素（这个子列表），更新父状态
                }
                else {
                    if (i != n) invalid = true; // 不能有多余字符
                }
            }
            else if (ch == '[') {
                st += '0'; // 开始一个新的子列表，压入新状态
                i++;
            }
            else {
                // 解析整数（可带'-'）
                if (ch == '-') {
                    if (i + 1 >= n || !(s[i + 1] >= '0' && s[i + 1] <= '9')) {
                        invalid = true;
                        break;
                    }
                    i++;
                }
                if (!(s[i] >= '0' && s[i] <= '9')) {
                    invalid = true;
                    break;
                }
                while (i < n && (s[i] >= '0' && s[i] <= '9')) i++; // 读取完整数字
                st[st.size() - 1] = '1'; // 已有元素，更新当前状态
            }
        }

        else if (state == 1) { // 元素后期望','或']'
            if (ch == ',') {
                st[st.size() - 1] = '2'; // 更改为逗号后状态
                i++;
            }
            else if (ch == ']') {
                st.resize(st.size() - 1); // 闭合当前列表，弹出栈顶
                i++;
                if (!st.empty()) {
                    st[st.size() - 1] = '1'; // 关闭的子列表作为一个元素，更新父状态
                }
                else {
                    if (i != n) invalid = true; // 不能有多余字符
                }
            }
            else {
                invalid = true; // 既不是','也不是']'，非法
            }
        }

        else if (state == 2) { // 逗号后期望元素
            if (ch == '[') {
                st += '0'; // 开始新的子列表，压入新状态
                i++;
            }
            else {
                // 解析整数（可带'-'）
                if (ch == '-') {
                    if (i + 1 >= n || !(s[i + 1] >= '0' && s[i + 1] <= '9')) {
                        invalid = true;
                        break;
                    }
                    i++;
                }
                if (!(s[i] >= '0' && s[i] <= '9')) {
                    invalid = true;
                    break;
                }
                while (i < n && (s[i] >= '0' && s[i] <= '9')) i++; // 读取完整数字
                st[st.size() - 1] = '1'; // 已有元素，更新当前状态
            }
        }

        else {
            invalid = true; // 状态错误
        }
    }

    if (!invalid && !st.empty()) invalid = true; // 没有全部闭合

    cout << (invalid ? "格式非法！" : "格式合法！") << endl;
    return 0;
}

/*
 * 什么是"栈"？- 通俗解释
 *
 * 栈就像一个只能从顶部放入和取出物品的容器，比如一摞盘子：
 * - 后放入的盘子在最上面（后进先出）
 * - 只能从最上面取盘子
 * - 不能从中间取盘子
 *
 * 在这个程序中，我们用字符串st来模拟栈的行为：
 * - 压入操作：st += '0' （在字符串末尾添加字符）
 * - 弹出操作：st.resize(st.size() - 1) （删除字符串最后一个字符）
 * - 查看栈顶：st[st.size() - 1] （访问字符串最后一个字符）
 *
 * 栈在这里的作用是记录我们当前正在处理哪个列表层级：
 * - 当遇到'['时，我们进入一个新列表，将新状态压入栈
 * - 当遇到']'时，表示当前列表处理完成，从栈中弹出该状态
 * - 栈中的每个状态代表一个正在处理的列表，最右边的字符代表当前正在处理的列表
 *
 * 举个例子，对于输入"[1,[2,3],4]"：
 * - 开始时栈中有'0'（代表外层列表）
 * - 遇到第一个'['，栈变成'00'（代表外层列表中的子列表）
 * - 遇到']'，栈变回'0'（子列表处理完成）
 * - 最后遇到']'，栈变为空（外层列表处理完成）
 *
 * 这种方式能帮助我们跟踪嵌套结构，确保每个'['都有对应的']'。
 */
