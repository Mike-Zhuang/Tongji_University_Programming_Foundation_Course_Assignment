#include <iostream>
using namespace std;
int main() {
    char color, sound, touch;
    double density;
    cin >> color >> sound >> touch >> density;
    if (color == 'W') {
        cout << "这个瓜是坏瓜。";
    }
    else if (color == 'B') {
        if (density < 0.4) {
            cout << "这个瓜是好瓜。";
        }
        else {
            cout << "这个瓜是坏瓜。";
        }
    }
    else if (color == 'G') {
        if (sound == 'M') {
            cout << "这个瓜是好瓜。";
        }
        else if (sound == 'C') {
            if (touch == 'H') {
                cout << "这个瓜是好瓜。";
            }
            else {
                cout << "这个瓜是坏瓜。";
            }
        }
    }
}