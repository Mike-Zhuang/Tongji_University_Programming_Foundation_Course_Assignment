#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char ans[26], guess[26];
    cin >> ans;
    int n = (int)strlen(ans);
    char progress [26];
    for (int i = 0; i < n; i++) {
        progress[i] = '*';
    }
    progress[n] = '\0';

    cout << progress << endl;
    while (cin >> guess) {
        if (strcmp (guess, ans) == 0) {
            cout << ans << '\n';
            break;
        }
        for (int i = 0; i < n; ++i) {
            if (progress[i] == '*' && guess[i] == ans[i]) {
                progress[i] = ans[i];
            }
        }
        cout << progress << '\n';
    }
}