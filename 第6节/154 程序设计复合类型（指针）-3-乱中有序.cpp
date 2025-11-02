#include <iostream>
#define ARRAY_LENGTH 50
using namespace std;

void decode(char* p)
{
    /****************** TODO ******************/
    int len = 0;
    while (*(p + len) != '\0') {
        len++;
    }

    int left = 0, right = len - 1;
    while (left <= right) {
        cout << *(p + left);
        left++;
        if (left <= right) {
            cout << *(p + right);
            right--;
        }
    }

    /**************** TODO-END ****************/
}

int main()
{
    char str[ARRAY_LENGTH] = {};
    cin.getline(str, ARRAY_LENGTH);

    decode(str);

    return 0;
}