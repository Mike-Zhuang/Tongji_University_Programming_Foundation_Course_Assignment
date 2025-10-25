#include <iostream>
using namespace std;
void hanoi(int n, char from, char to, char via) {
    static int step = 1;
    if (n == 1) {
        cout << step++ << ". " << from << " -> " << to << endl;
        return;
    }
    hanoi(n - 1, from, via, to);//先把n-1个圆盘移动到中间柱
    cout << step++ << ". " << from << " -> " << to << endl;
    hanoi(n - 1, via, to, from);//再把n-1个圆盘从中间柱移动到目标柱
}

int main() {
    int n;
    char from, to, via;
    cin >> from >> to;
    cin >> n;
    if ((from == 'A' && to == 'B') || (from == 'B' && to == 'A')) {
        via = 'C';
    }
    else if ((from == 'A' && to == 'C') || (from == 'C' && to == 'A')){
        via = 'B';
    }
    else if ((from == 'B' && to == 'C') || (from == 'C' && to == 'B')){
        via = 'A';
    }
    else {
        return 0;
    }
    hanoi(n, from, to, via);
    return 0;
}