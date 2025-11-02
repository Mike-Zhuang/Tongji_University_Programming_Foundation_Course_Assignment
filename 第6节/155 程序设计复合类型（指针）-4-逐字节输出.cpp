#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    for (int i = 0; i < 5; ++i)
    {
        if (!(cin >> arr[i]))
            return 0;
    }

    signed char *p = (signed char *)(arr);
    int total = 5 * (sizeof(int));

    for (int i = 0; i < total; ++i)
    {
        if (i)
        {
            cout << ' ';
        }
        cout << (int)(p[i]);
    }
    cout << '\n';
    return 0;
}


