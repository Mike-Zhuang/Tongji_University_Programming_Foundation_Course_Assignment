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
    int cardA;//书院中每有一个建筑，科技产出便 +10
    int cardB;//城市中每一个人口额外产生 2点科技值。
    int cardC;//如果粮食产出为正，则城市中额外产生与粮食产出等量的科技值产出。
    Condition() : population(0), farm(0), campus(0), library(0), university(0), lab(0), cardA(0), cardB(0), cardC(0) {}
};

int main() {
    Condition city_condition;
    cin >> city_condition.name >> city_condition.population >> city_condition.farm;
    string action;
    city_condition.cardA = 0;
    city_condition.cardB = 0;
    city_condition.cardC = 0;
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
        else if (action == "set") {
            string next;
            cin >> next;
            if (next == "A") {
                city_condition.cardA = 1;
                city_condition.cardB = 0;
                city_condition.cardC = 0;

            }
            if (next == "B") {
                city_condition.cardB = 1;
                city_condition.cardA = 0;
                city_condition.cardC = 0;
            }
            if (next == "C") {
                city_condition.cardC = 1;
                city_condition.cardA = 0;
                city_condition.cardB = 0;
            }
        }
        else if (action == "quit") {
            break;
        }
        int food = 4 * city_condition.farm - 2 * city_condition.population;
        int tech = int(city_condition.campus * 4 + city_condition.library * 4 + city_condition.university*8 + city_condition.lab*16 +
                   city_condition.population *(city_condition.library*0.5 + city_condition.university*1 + city_condition.lab*1)+
                   (max(city_condition.population, 10) - 10) * city_condition.lab * 2+
                   city_condition.cardA * (city_condition.library + city_condition.university + city_condition.lab) * 10+
                   city_condition.cardB * city_condition.population *2+
                   city_condition.cardC * max(0,food) ) ;
        cout << city_condition.name << " " << city_condition.population << " " << food << " " << tech << endl;
    }
}
