#include <iostream>
#include <iomanip>
using namespace std;

/****************** TODO ******************/

void statistic(int arr[], int n, int &max, int &min, float &avg, float &var)
{
    max = arr[0];
    min = arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        sum += arr[i];
    }
    avg = (float)sum / n;
    double up_var = 0.0;
    for (int i = 0; i < n; i++)
    {
        up_var += pow((arr[i] - avg), 2);
    }
    var = (float)(up_var / n);
}

/**************** TODO-END ****************/

int main()
{
    const int ARRAY_LENGTH = 10;
    int arr[ARRAY_LENGTH] = {};
    for (int i = 0; i < ARRAY_LENGTH; ++i)
    {
        cin >> arr[i];
    }

    // 最大值和最小值
    int max = 0, min = 0;
    // 平均数和方差
    float avg = 0, var = 0;

    statistic(arr, ARRAY_LENGTH, max, min, avg, var);

    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
    // 输出平均数和方差时，保留两位小数
    cout << fixed << setprecision(2);
    cout << "avg: " << avg << endl;
    cout << "var: " << var << endl;

    return 0;
}