#include <iostream>
#include <string>
using namespace std;
struct condition {
    int farm_num;
    int population_num;
};
int main() {
    string city_name;
    condition city_condition{};
    cin >> city_name >> city_condition.population_num >> city_condition.farm_num;
    string action;
    while (cin >> action) {
        if (action == "farm") {
            int temp;
            cin >> temp;
            city_condition.farm_num += temp;
            if (city_condition.farm_num < 0) {
                city_condition.farm_num = 0;
            }
            string temp_production;
            if ((-2) * city_condition.population_num + 4 * city_condition.farm_num >= 0) {
                temp_production = "+" + to_string((-2) * city_condition.population_num + 4 * city_condition.farm_num) + "粮";
            }
            else {
                temp_production = to_string((-2) * city_condition.population_num + 4 * city_condition.farm_num) + "粮";
            }
            cout << city_name << " " << city_condition.population_num << "人 " << temp_production << endl;
        }
        else if (action == "population") {
            int temp;
            cin >> temp;
            city_condition.population_num += temp;
            if (city_condition.population_num < 0) {
                city_condition.population_num = 0;
            }
            string temp_production;
            if ((-2) * city_condition.population_num + 4 * city_condition.farm_num >= 0) {
                temp_production = "+" + to_string((-2) * city_condition.population_num + 4 * city_condition.farm_num) + "粮";
            }
            else {
                temp_production = to_string((-2) * city_condition.population_num + 4 * city_condition.farm_num) + "粮";
            }
            cout << city_name << " " << city_condition.population_num << "人 " << temp_production << endl;
        }
        else if (action == "quit") {
            break;
        }
    }
}