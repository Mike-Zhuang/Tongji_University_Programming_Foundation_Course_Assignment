#include <iostream>
#define STRING_MAX_LENGTH 200
using namespace std;

/****************** TODO ******************/

int to_upper(char convert[]) {
    int count = 0;
    for (int i = 0; convert[i] != '\0'; ++i) {
        if (convert[i] >= 'a' && convert[i] <= 'z') {
            convert[i] = convert[i] - 'a' + 'A';
            ++count;
        }
    }
    return count;
}

/**************** TODO-END ****************/

int main()
{
    char str[STRING_MAX_LENGTH];
    cin.getline(str, STRING_MAX_LENGTH);

    int num = to_upper(str);
    // 想一想，字符串内容改变了吗？为什么？

    cout << "共转换" << num << "个字母。" << endl;
    cout << str << endl;

    return 0;
}