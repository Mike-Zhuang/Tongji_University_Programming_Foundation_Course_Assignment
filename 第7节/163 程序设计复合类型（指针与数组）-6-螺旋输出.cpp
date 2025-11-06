#include <iostream>
using namespace std;

void anticlockwise_print(int *array, int rows, int cols)
{
    /****************** TODO ******************/

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int total = rows * cols;
    int printed = 0;

    while (left <= right && top <= bottom && printed < total)
    {
        // 左
        for (int r = top; r <= bottom && printed < total; ++r)
        {
            if (printed > 0)
            {
                cout << " ";
            }
            cout << array[r * cols + left];
            printed++;
        }
        left++;

        // 下
        for (int c = left; c <= right && printed < total; ++c)
        {
            if (printed > 0)
            {
                cout << " ";
            }
            cout << array[bottom * cols + c];
            printed++;
        }
        bottom--;

        // 右
        for (int r = bottom; r >= top && printed < total; --r)
        {
            if (printed > 0)
            {
                cout << " ";
            }
            cout << array[r * cols + right];
            printed++;
        }
        right--;

        // 上
        for (int c = right; c >= left && printed < total; --c)
        {
            if (printed > 0)
            {
                cout << " ";
            }
            cout << array[top * cols + c];
            printed++;
        }
        top++;
    }

    /**************** TODO-END ****************/
}

int main()
{
    const int max_rows = 20, max_cols = 20;
    int rows = 0, cols = 0;
    cin >> rows >> cols;

    // 用一维数组存储矩阵
    int array[max_rows * max_cols] = {};

    // 读取矩阵
    for (int i = 0; i < rows * cols; ++i)
    {
        cin >> array[i];
    }

    anticlockwise_print(array, rows, cols);

    return 0;
}