#include <iostream>
#include <string>
using namespace std;

class Condition {
public:
    string name;
    int population;
    int farm;
    int campus;
    int library;
    int university;
    int lab;
    Condition() : population(0), farm(0), campus(0), library(0), university(0), lab(0) {}
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
            if (next == "library") {
                if (city_condition.campus == 1) {
                    city_condition.library = 1;
                }
                else {
                    city_condition.library = 0;
                }
            }
            if (next == "university") {
                if (city_condition.library == 1) {
                    city_condition.university = 1;
                }
                else {
                    city_condition.university = 0;
                }
            }
            if (next == "lab") {
                if (city_condition.university == 1) {
                    city_condition.lab = 1;
                }
                else {
                    city_condition.lab = 0;
                }
            }
        }
        else if (action == "quit") {
            break;
        }
        int food = 4 * city_condition.farm - 2 * city_condition.population;
        int tech = (int)(city_condition.campus * 4 + city_condition.library * 4 + city_condition.university*8 + city_condition.lab*16 +
                   city_condition.population *(city_condition.library*0.5 + city_condition.university*1 + city_condition.lab*1)+
                   (max(city_condition.population, 10) - 10) * city_condition.lab * 2);
        cout << city_condition.name << " " << city_condition.population << " " << food << " " << tech << endl;
    }
}
