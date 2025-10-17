#include <iostream>
using namespace std;
double import_distance() {
    double distance;
    cout << "请输入距离：";
    cin >> distance;
    return distance;
}
double calculate_time(double distance) {
    double time;
    const double velocity = 0.01;
    time = distance / velocity;
    return time;
}
void export_time(double time) {
    cout << "三体人需要" << time << "年到达地球。" << endl;
}
int main() {
    double distance, time;
    distance = import_distance();
    time = calculate_time(distance);
    export_time(time);
    return 0;
}