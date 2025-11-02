#include <iostream>
#include <string>
using namespace std;

class Condition {
public:
    string name;
    int population;
    int farm;
    int campus;
    Condition() : population(0), farm(0), campus(false) {}
};

int main() {
    Condition city_condition;
    cin >> city_condition.name >> city_condition.population >> city_condition.farm;
    string action;
    while (cin >> action) {
        int value = 0;
        if (action == "farm" || action == "population") {
            cin >> value;
            if (action == "farm") {
                city_condition.farm += value;
                if (city_condition.farm < 0) city_condition.farm = 0;
            }
            else if (action == "population") {
                city_condition.population += value;
                if (city_condition.population < 0) city_condition.population = 0;
            }
        }
        else if (action == "build") {
            string next;
            cin >> next;
            if (next == "campus") {
                city_condition.campus = 1;
            }
        }
        else if (action == "quit") {
            break;
        }
        int food = 4 * city_condition.farm - 2 * city_condition.population;
        int tech = city_condition.campus * 4;
        cout << city_condition.name << " " << city_condition.population << " " << food << " " << tech << endl;
    }
}
