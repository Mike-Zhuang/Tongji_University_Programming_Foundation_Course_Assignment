#include <iostream>
#include <cstring>
using namespace std;

const int max_line = 200;
const int max_name = 200;
const int max_depth = 205;

// Function to print the current path
void print_path(char parts[][max_name], int depth) {
    cout << "C:\\";
    for (int i = 0; i < depth; i++) {
        cout << parts[i];
        if (i + 1 < depth) cout << "\\";
    }
    cout << "\n";
}

int main() {
    char parts[max_depth][max_name];
    int depth = 0;

    // Initial path: C:\Users\Student
    strcpy_s(parts[depth++], "Users");
    strcpy_s(parts[depth++], "Student");

    print_path(parts, depth);

    char line[max_line];
    while (cin.getline(line, max_line)) {
        if (strcmp(line, "quit") == 0) {
            break;
        }

        int len = (int)strlen(line);
        char seg[max_name];
        int seg_len = 0;

        for (int p = 3; p <= len; ++p) {

            char ch;
            if (p < len) {
                ch = line[p];     // 正常读取当前字符
            }
            else {
                ch = '\0';        // 走到行尾，多喂一个 '\0' 收尾
            }

            if (ch == '\\' || ch == '\0') {
                // 到了分隔符或行尾，完成一个片段
                if (seg_len > 0) {
                    seg[seg_len] = '\0';
                    if (strcmp(seg, ".") == 0) {
                        // 当前级：不操作
                    }
                    else if (strcmp(seg, "..") == 0) {
                        // 上一级：根目录不再上移
                        if (depth > 0) {
                            depth--;
                        }
                    }
                    else {
                        // 下一级
                        if (depth < max_depth) {
                            strcpy_s(parts[depth], seg);
                            depth++;
                        }
                    }
                    seg_len = 0;//清空
                }
                else {
                    // Ignore empty segments
                }
            }
            else {
                if (seg_len + 1 < max_name) {
                    seg[seg_len++] = ch;
                }
            }
        }

        print_path(parts, depth);
    }
    return 0;
}