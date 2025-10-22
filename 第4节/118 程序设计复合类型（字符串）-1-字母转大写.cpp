#include <iostream>
using namespace std;

int main() {
    char convert[200] = {0};

    if (!(cin.getline(convert, 200))) {
        return 0;
    }

    int count = 0;
    for (int i = 0; convert[i] != '\0'; ++i) {
        if (convert[i] >= 'a' && convert[i] <= 'z') {
            convert[i] = convert[i] - 'a' + 'A';
            ++count;
        }
    }

    cout << "共转换" << count << "个字母。" << endl;
    cout << convert << endl;
    return 0;
}
