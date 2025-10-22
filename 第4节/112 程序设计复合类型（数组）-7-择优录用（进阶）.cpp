#include <iostream>
#include <iomanip>
using namespace std;

int findminvalue(const double a[], int n) {
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[idx]) {
            idx = i;
        }
    }
    return idx;
}

void sortnum(double a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    double selected[10];
    int count = 0;
    double sum = 0.0;

    double x;
    while (cin >> x) {
        if (x == -1) break;

        if (count == 0) {
            if (x >= 3.50) {
                selected[count++] = x;
                sum += x;
            }
        }
        else {
            double avg = sum / count;
            if (count < 10) {
                if (x > avg) {
                    selected[count++] = x;
                    sum += x;
                }
            }
            else { // count == 10
                if (x > avg) {
                    int minIdx = findminvalue(selected, count);
                    if (x > selected[minIdx]) {
                        sum = sum - selected[minIdx] + x;
                        selected[minIdx] = x;
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(2);

    cout << "最终被录用绩点情况：" << endl;
    if (count > 0) {
        sortnum(selected, count);
        for (int i = 0; i < count; ++i) {
            cout << selected[i] << " ";
        }
    }
    cout << endl;

    cout << "平均绩点：" << endl;
    double avg;
    if (count > 0) {
        avg = sum / count;
    }
    else {
        avg = 0.0;
    }
    cout << avg << endl;

    return 0;
}