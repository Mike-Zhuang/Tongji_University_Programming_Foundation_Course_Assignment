#include <iostream>
#include <string>
using namespace std;

int main() {
    string line, result;
    while (getline(cin, line) && line != " ") {
        result += line;
    }
    cout << result.length() << endl;
    cout << result << endl;
    return 0;
}
