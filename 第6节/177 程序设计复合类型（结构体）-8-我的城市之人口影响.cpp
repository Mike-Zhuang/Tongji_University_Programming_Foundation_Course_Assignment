#include <iostream>
#include <string>
using namespace std;

struct Condition {
    string name;
    int population;
    int farm;
    int plantation;
    int mine;
};

int main() {
    Condition city_condition;
    city_condition.plantation = 0;
    city_condition.mine = 0;
    cin >> city_condition.name >> city_condition.population >> city_condition.farm;
    string action;
    int factory = 0;
    int market = 0;
    while (cin >> action) {
        int value = 0;

        if (action == "farm" || action == "plantation" || action == "mine" || action == "population") {
            cin >> value;
            if (action == "farm") {
                city_condition.farm += value;
                if (city_condition.farm < 0) {
                    city_condition.farm = 0;
                }
            }
            else if (action == "plantation") {
                city_condition.plantation += value;
                if (city_condition.plantation < 0) {
                    city_condition.plantation = 0;
                }
            }
            else if (action == "mine") {
                city_condition.mine += value;
                if (city_condition.mine < 0) {
                    city_condition.mine = 0;
                }
            }
            else if (action == "population") {
                city_condition.population += value;
                if (city_condition.population < 0) {
                    city_condition.population = 0;
                }
            }
        }
        else if (action == "build") {
            string temp;
            cin >> temp;
            if (temp == "factory") {

                factory = 1;
            }

            else if (temp == "market") {

                market = 1;
            }
        }
        else if (action == "quit") {
            break;
        }
        int food = 4 * city_condition.farm + 3 * city_condition.plantation - 2 * city_condition.population;
        int gold = 2 * city_condition.plantation + 2 * city_condition.mine - 10 * factory + 2 * market * city_condition.population;
        int hammer = 3 * city_condition.mine + (1 + 2 * factory) * city_condition.population;
        cout << city_condition.name << " " << city_condition.population << "人 ";
        if (food >= 0) {
            cout << "+" << food << "粮 ";
        }
        else {
            cout << food << "粮 ";
        }
        if (gold >= 0) {
            cout << "+" << gold << "金 ";
        }
        else {
            cout << gold << "金 ";
        }
        cout << "+" << hammer << "锤" << endl;
    }
}