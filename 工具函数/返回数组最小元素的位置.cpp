int findminvalue(const double a[], int n) {
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[idx]) {
            idx = i;
        }
    }
    return idx;
}
//这段代码的作用是：在长度为n的double数组a中，找到最小值的下标，并返回该下标。
//例如，如果你有一个数组a，调用findminvalue(a, n)，返回值就是数组中最小元素的位置（下标）。