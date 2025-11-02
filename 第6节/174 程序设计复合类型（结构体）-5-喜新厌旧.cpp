#include <iostream>
#include <string>
using namespace std;

struct info {
    string book_name;
    string author_name;
    int pages = 0;
    int order = 0;
    int joined = 0;
};

int main() {
    info book[10];
    int i = 0;
    int seq = 0;
    string action;

    while (cin >> action) {
        if (action == "put") {
            string book_name, author_name;
            int pages;
            cin >> book_name >> author_name >> pages;

            if (i < 10) {
                for (int k = 0; k < i; ++k) {
                    book[k].order++;
                }

                book[i].book_name = book_name;
                book[i].author_name = author_name;
                book[i].pages = pages;
                book[i].order = 0;
                book[i].joined = ++seq;
                i++;
            }
            else {

                int max_order = 0;
                for (int k = 1; k < 10; ++k) {
                    if (book[k].order > book[max_order].order) {
                        max_order = k;
                    }
                }//找到最大下标

                for (int k = 0; k < 10; ++k) {
                    if (k != max_order) {
                        book[k].order++;
                    }
                }//其它书时间++

                book[max_order].book_name = book_name;
                book[max_order].author_name = author_name;
                book[max_order].pages = pages;
                book[max_order].order = 0;
                book[max_order].joined = ++seq;
            }
        }
        else if (action == "read") {
            string book_read;
            cin >> book_read;
            int read_order = -1;
            for (int j = 0; j < i; ++j) {
                if (book[j].book_name == book_read) {
                    read_order = j;
                    break;
                }// 找到想读的书
            }
            if (read_order != -1) {
                for (int k = 0; k < i; ++k) {
                    if (k == read_order) continue;
                    book[k].order++;
                }
                book[read_order].order = 0;
            }//想读的书放在0，其它书时间++
        }
        else if (action == "quit") {
            int printed = 0;
            bool used[10] = {false};
            while (printed < i) {
                int min = -1;//最小join的下标
                int min_joined = 114514;//最小join的值
                for (int k = 0; k < i; ++k) {
                    if (!used[k] && book[k].joined > 0 && book[k].joined < min_joined) {
                        min_joined = book[k].joined;
                        min = k;
                    }
                }
                cout << book[min].book_name << " " << book[min].author_name << " " << book[min].pages << endl;
                used[min] = true;
                printed++;
            }
            break;
        }
    }
    return 0;
}