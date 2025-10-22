#include <iostream>
#include <string>
using namespace std;
int main() {
    string str, command;

    while (getline(cin,command)) {
        if (command == "q") {
            break;
        }

        if (command == "1") {
            cout << str.size() << '\n';
        }
        else if (command == "2") {
            cout << str << '\n';
        }
        else if (command == "3") {
                string mode;
                if (!getline(cin, mode)) {
                    break;
                }
                if (mode == "U") {
                    for (size_t i = 0; i < str.size(); ++i) {
                        char c = str[i];
                        if (c >= 'a' && c <= 'z') {
                            str[i] = char(c - 'a' + 'A');
                        }
                    }
                } else if (mode == "L") {
                    for (size_t i = 0; i < str.size(); ++i) {
                        char c = str[i];
                        if (c >= 'A' && c <= 'Z') {
                            str[i] = char(c - 'A' + 'a');
                        }
                    }
                }
        }
        else if (command == "4") {
            string s, posLine;
            if (!getline(cin, s)) break;
            if (!getline(cin, posLine)) break;

            int n = 0;
            bool neg = false;
            size_t i = 0;
            if (!posLine.empty() && posLine[0] == '-') { neg = true; i = 1; }
            for (; i < posLine.size(); ++i) {
                char c = posLine[i];
                if (c >= '0' && c <= '9') n = n * 10 + (c - '0');
            }
            if (neg) n = -n;
            if (n < 0) n = 0;
            if (n > (int)str.size()) n = (int)str.size();

            str.insert((size_t)n, s);

        }
        else if (command == "5") {
            string s1, s2;
            if (!getline(cin, s1)) break;
            if (!getline(cin, s2)) break;
            size_t p = str.find(s1);
            if (p < str.size()) {
                str.replace(p, s1.size(), s2);
            }
        }
    }
    if (!str.empty()) cout << str << '\n';
    return 0;
}