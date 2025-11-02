#include <iostream>
#include <string>
using namespace std;

struct Condition {
    string name;
    int population;//hammer+1&food-2
    struct farm {
        int hill;//food+2
        int plain;//food+3
        int floodplain;//food+4
    } farm;
    struct plantation{
        int fabric;//gold+4
        int food;//food+4
    } plantation;
    struct mine {
        int material;//hammer+4&gold+2
        int precious;//hammer+2&gold+4
    } mine;
};

int main() {
    Condition city_condition;
    city_condition.farm = {0,0,0};
    city_condition.plantation= {0,0};
    city_condition.mine = {0,0};
    cin >> city_condition.name >> city_condition.population;
    string action;
    int factory = 0;
    int market = 0;
    while (cin >> action) {
        int value = 0;
        if (action == "population") {
            cin >> value;
            city_condition.population += value;
            if (city_condition.population < 0) {
                city_condition.population = 0;
            }
        }

        else if (action == "farm" || action == "plantation" || action == "mine") {
            string temp;
            if (action == "farm") {
                cin >> temp;
                cin >> value;
                if (temp == "hill") {
                    city_condition.farm.hill += value;
                    if (city_condition.farm.hill < 0) {
                        city_condition.farm.hill = 0;
                    }
                }
                else if (temp == "plain") {
                    city_condition.farm.plain += value;
                    if (city_condition.farm.plain < 0) {
                        city_condition.farm.plain = 0;
                    }
                }
                else if (temp == "floodplain") {
                    city_condition.farm.floodplain += value;
                    if (city_condition.farm.floodplain < 0) {
                        city_condition.farm.floodplain = 0;
                    }
                }
            }
            else if (action == "plantation") {
                cin >> temp;
                cin >> value;
                if (temp == "fabric") {
                    city_condition.plantation.fabric += value;
                    if (city_condition.plantation.fabric < 0) {
                        city_condition.plantation.fabric = 0;
                    }
                }
                else if (temp == "food") {
                    city_condition.plantation.food += value;
                    if (city_condition.plantation.food < 0) {
                        city_condition.plantation.food = 0;
                    }
                }
            }
            else if (action == "mine") {
                cin >> temp;
                cin >> value;
                if (temp == "material") {
                    city_condition.mine.material += value;
                    if (city_condition.mine.material < 0) {
                        city_condition.mine.material = 0;
                    }
                }
                else if (temp == "precious") {
                    city_condition.mine.precious += value;
                    if (city_condition.mine.precious < 0) {
                        city_condition.mine.precious = 0;
                    }
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

        int food = 2 * city_condition.farm.hill + 3 * city_condition.farm.plain + 4 * city_condition.farm.floodplain + 4 * city_condition.plantation.food - 2 * city_condition.population;
        int gold = 4 * city_condition.plantation.fabric + 2 * city_condition.mine.material + 4 * city_condition.mine.precious + 2 * market * city_condition.population - 10 * factory;
        int hammer = city_condition.mine.material * 4 + city_condition.mine.precious * 2 + (1 + 2 * factory) * city_condition.population;
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