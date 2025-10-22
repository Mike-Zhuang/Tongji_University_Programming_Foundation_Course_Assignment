bool isint(string input) {
    if (input.empty()) {
        return false;
    }
    int i = 0;
    if (input[0] == '-' || input[0] == '+') {
        i = 1;
    }
    if (i == input.size()) {
        return false; // Only a sign, no digits
    }
    for (; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}