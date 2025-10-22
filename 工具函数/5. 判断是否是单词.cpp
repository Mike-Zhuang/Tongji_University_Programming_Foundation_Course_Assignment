int isWord(char unworded) {
    if (unworded >= 'a' && unworded <= 'z') return 1;
    if (unworded >= 'A' && unworded <= 'Z') return 1;
    if (unworded >= '0' && unworded <= '9') return 1;
    if (unworded == '-' || unworded == '\'') return 1;
    return 0;
}