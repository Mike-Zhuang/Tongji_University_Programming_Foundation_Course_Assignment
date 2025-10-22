#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char uncompressed[205];
    if (!cin.getline(uncompressed, sizeof(uncompressed))) {
        return 0;
    }

    int length_umcompressed = (int)strlen(uncompressed);
    char compressed[205];
    int num = 0;

    for (int i = 0; i < length_umcompressed; ) {
        char now = uncompressed[i];
        int k = i + 1;
        while (k < length_umcompressed && uncompressed[k] == now) {
            k++;
        }
        int same_length = k - i;

        while (same_length > 0) {
            int unit_length = min(same_length, 9);
            compressed[num++] = now;
            compressed[num++] = '0' + unit_length;
            same_length -= unit_length;
        }
        i = k;
    }
    compressed[num] = '\0';

    if (num < length_umcompressed) {
        cout << compressed << endl;
    } else {
        cout << "压缩失败！" << endl;
    }
    return 0;
}