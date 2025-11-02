#include <iostream>
using namespace std;
class MyQueue {
public:
   int line[20] = {0};
   int i = 0;
   void push () {
      int temp;
      cin >> temp;
      line[i] = temp;
      i++;
   }
   void pop () {
      if (i == 0) {
         cout << "Error" << endl;
         return;
      }
      cout << line[0] << endl;
      for (int j = 0; j < 19; j++) {
         line[j] = line[j + 1];
      }
      line[i - 1] = 0;
      i--;
   }
   void max() {
      cout << sortnum_big_to_small(line, 20) << endl;
   }
   void min() {
      cout << sortnum_small_to_big(line, 20) << endl;
   }
   bool search(int x) {
      for (int i = 0; i < 20; i++) {
         if (line[i] == x) {
            return true;
         }

      }
      return false;
   }
   void quit() {
      exit(0);
   }


private:
   int sortnum_big_to_small(int a[], int n) {
      int temp[20] = {0};
      for (int i = 0; i < 19; i++) {
         temp[i] = a[i];
      }
      for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < n - 1 - i; j++) {
            if (temp[j] < temp[j + 1]) {
               int tem = temp[j];
               temp[j] = temp[j + 1];
               temp[j + 1] = tem;
            }
         }
      }
      return temp[0];
   }
   int sortnum_small_to_big(int a[], int n) {
      int temp[20] = {0};
      for (int i = 0; i < 19; i++) {
         temp[i] = a[i];
      }
      for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < n - 1 - i; j++) {
            if (temp[j] > temp[j + 1]) {
               int tem = temp[j];
               temp[j] = temp[j + 1];
               temp[j + 1] = tem;
            }
         }
      }
      return temp[0];
   }
};

int main() {
   MyQueue my_queue;
   string action;
   while (true) {
      cin >> action;
      if (action == "push") {
         my_queue.push();
      }
      else if (action == "pop") {
         my_queue.pop();
      }
      else if (action == "max") {
         my_queue.max();
      }
      else if (action == "min") {
         my_queue.min();
      }
      else if (action == "search") {
         int x;
         cin >> x;
         if (my_queue.search(x)) {
            cout << "true" << endl;
         }
         else {
            cout << "false" << endl;
         }
      }
      else if (action == "quit") {
         my_queue.quit();
      }
   }
   return 0;
}
