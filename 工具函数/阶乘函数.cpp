double jiecheng(int n) {
    int i;
    int result = 1;
    for (i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}