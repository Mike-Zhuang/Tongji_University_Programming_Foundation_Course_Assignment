#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double score;
    int hired_count = 0;
    double sum = 0.0;
    double avg = 0.0;
    cout << fixed << setprecision(2);
    while (cin >> score) {
        if (score == -1) {
            break;
        }

        bool hire = false;
        if (hired_count >= 10) {
            hire = false;
        }
        else if (hired_count == 0) {
            hire = (score >= 3.50);
        }
        else {
            avg = sum / hired_count;
            hire = (score > avg);
        }

        if (hire) {
            cout << score << "被录用了。" << endl;
            sum += score;
            hired_count++;
        }
        else {
            cout << score << "未被录用。" << endl;
        }

    }
}