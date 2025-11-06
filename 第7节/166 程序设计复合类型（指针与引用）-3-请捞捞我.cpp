#include <iostream>
using namespace std;

/****************** TODO ******************/

int &find_min(int arr[], int length)
{
    int x = arr[0];
    int pos = 0;
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < x)
        {
            x = arr[i];
            pos = i;
        }
    }
    return arr[pos];
}

/**************** TODO-END ****************/

int main()
{
    const int ARRAY_LENGTH = 10;
    int arr[ARRAY_LENGTH] = {};
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        cin >> arr[i];
    }

    // 五次修改操作
    for (int i = 0; i < 5; i++)
    {
        cin >> find_min(arr, ARRAY_LENGTH); // 修改最小值
    }

    // 输出数组
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}